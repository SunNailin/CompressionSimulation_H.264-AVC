#include "h264sender.h"

H264Sender::H264Sender(QObject *parent) :
    QObject(parent)
{
    _rtpHeader.v = 2;   // The version number is 2, it defined by protocol RFC3550
    _rtpHeader.p = 0;   // There is no padding bit
    _rtpHeader.x = 0;   // There is no extension
    _rtpHeader.cc = 0;  // There is no CSRC
    _rtpHeader.m = 1;   // Mark the end of a nalu
    _rtpHeader.pt = 96; // H264 payload type
    _rtpHeader.seqnum = 1224;       // Just a random number
    _rtpHeader.timestamp = 0;       // Just a random number
    _rtpHeader.ssrc = 1231;         // Just a random number

    _seqNumber = 1224;
    _timestamp = 0;

    _udpSocket = new QUdpSocket(this);
    _udpSocket->bind(52748, QUdpSocket::ShareAddress);  // bind socket's port
}

H264Sender::~H264Sender()
{
    delete _udpSocket;
}

int H264Sender::sendPacket(char *buf, int size, unsigned int timeIncrease)
{
    char* pbuf = buf;   // use to store pure data
    int len = size;

    // Preprocessing header
    if( (pbuf[0] == 0) && (pbuf[1] == 0) && (pbuf[2] == 1) )  // 0x000001 header
    {
        memcpy((void*)&_naluHead, (void*)&pbuf[3], 1);
        pbuf = pbuf + 4;
        len = len - 4;
    }
    else if( (pbuf[0] == 0) && (pbuf[1] == 0) && (pbuf[2] == 0) && (pbuf[3] == 1) )     // 0x00000001 header
    {
        memcpy((void*)&_naluHead, (void*)&pbuf[4], 1);
        pbuf = pbuf + 5;
        len = len - 5;
    }
    else
    {
        qDebug()<<"Some error occur, cann't find correct nalu header";
        return -1;
    }

    // begin send packet
    QByteArray byteArray;
    _timestamp += timeIncrease;
    qint64 dataSize;
    if( len <= MAXSIZE )    // send nalu with one rtp packet
    {
        // filling rtphead
        _seqNumber++;
        _rtpHeader.seqnum = this->htons(_seqNumber);
        _rtpHeader.timestamp = this->hton(_timestamp);
        _rtpHeader.m = 1;
        byteArray.clear();
        byteArray.append((char*)&_rtpHeader, sizeof(RtpHeader));

        // filling naluhead
        byteArray.append((char*)&_naluHead, sizeof(NaluHeader));

        // write data
        byteArray.append(pbuf, len);

        // send data for all target IP
        for( int i = 0; i<_destVector.size(); i++ )
        {
            dataSize = _udpSocket->writeDatagram(byteArray, _destVector[i].addr, _destVector[i].port);
            if (dataSize != byteArray.length()) {
                qDebug()<<"packet "<<_seqNumber<<"send faile. "<<_udpSocket->errorString();
            }
        }
    }
    else    // use several rtp packet to send nalu
    {
        int n = len/MAXSIZE;
        int m = len%MAXSIZE;
        for (int i = 0; i <= n; ++i)
        {
            _seqNumber++;
            if ( i == 0 )   // first packet
            {
                // filling rtphead
//                _timestamp += _increaseStep;
                _rtpHeader.seqnum = this->htons(_seqNumber);
                _rtpHeader.timestamp = this->hton(_timestamp);
                _rtpHeader.m = 0;
                byteArray.clear();
                byteArray.append((char*)&_rtpHeader, sizeof(RtpHeader));

                // filling fu-indicator
                NaluHeader fuindicator;
                fuindicator.type = 28;      // FU-A
                fuindicator.nri = _naluHead.nri;
                fuindicator.f = _naluHead.f;
                byteArray.append((char*)&fuindicator, sizeof(NaluHeader));

                // filling fu-header
                FuHeader fuhead;
                fuhead.s = 1;
                fuhead.r = 0;
                fuhead.e = 0;
                fuhead.type = _naluHead.type;
                byteArray.append((char*)&fuhead, sizeof(FuHeader));

                // filling data
                byteArray.append(pbuf, MAXSIZE);
                pbuf = pbuf + MAXSIZE;

                // send data
                for (int i = 0; i < _destVector.size(); ++i)
                {
                    dataSize = _udpSocket->writeDatagram(byteArray, _destVector[i].addr, _destVector[i].port);
                    if (dataSize != byteArray.length()) {
                        qDebug()<<"packet "<<_seqNumber<<"send faile. "<<_udpSocket->errorString();
                    }
                }
            }
            else if ( i == n )      // last packet
            {
                // filling rtphead
                _rtpHeader.seqnum = this->htons(_seqNumber);
                _rtpHeader.m = 1;
                byteArray.clear();
                byteArray.append((char*)&_rtpHeader, sizeof(RtpHeader));

                // filling fu-indicator
                NaluHeader fuindicator;
                fuindicator.type = 28;      // FU-A
                fuindicator.nri = _naluHead.nri;
                fuindicator.f = _naluHead.f;
                byteArray.append((char*)&fuindicator, sizeof(NaluHeader));

                // filling fu-header
                FuHeader fuhead;
                fuhead.s = 0;
                fuhead.r = 0;
                fuhead.e = 1;
                fuhead.type = _naluHead.type;
                byteArray.append((char*)&fuhead, sizeof(FuHeader));

                // filling data
                byteArray.append(pbuf, m);

                // send data
                for (int i = 0; i < _destVector.size(); ++i)
                {
                    dataSize = _udpSocket->writeDatagram(byteArray, _destVector[i].addr, _destVector[i].port);
                    if (dataSize != byteArray.length()) {
                        qDebug()<<"packet "<<_seqNumber<<"send faile. "<<_udpSocket->errorString();
                    }
                }
            }
            else
            {
                // filling rtphead
                _rtpHeader.seqnum = this->htons(_seqNumber);
                byteArray.clear();
                byteArray.append((char*)&_rtpHeader, sizeof(RtpHeader));

                // filling fu-indicator
                NaluHeader fuindicator;
                fuindicator.type = 28;      // FU-A
                fuindicator.nri = _naluHead.nri;
                fuindicator.f = _naluHead.f;
                byteArray.append((char*)&fuindicator, sizeof(NaluHeader));

                // filling fu-header
                FuHeader fuhead;
                fuhead.s = 0;
                fuhead.r = 0;
                fuhead.e = 0;
                fuhead.type = _naluHead.type;
                byteArray.append((char*)&fuhead, sizeof(FuHeader));

                // filling data
                byteArray.append(pbuf, MAXSIZE);
                pbuf = pbuf + MAXSIZE;

                // send data
                for (int i = 0; i < _destVector.size(); ++i)
                {
                    dataSize = _udpSocket->writeDatagram(byteArray, _destVector[i].addr, _destVector[i].port);
                    if (dataSize != byteArray.length()) {
                        qDebug()<<"packet "<<_seqNumber<<"send faile. "<<_udpSocket->errorString();
                    }
                }
            }
        }
    }
    return len;
}

int H264Sender::destNumber()
{
    return _destVector.size();
}

void H264Sender::clean()
{
    _destVector.clear();
}

void H264Sender::addDest(QHostAddress addr, quint16 port)
{
    Destination dest;
    dest.addr = addr;
    dest.port = port;
    _destVector.append(dest);
    qDebug()<<"Add new address";
    for( int i=0; i<_destVector.size(); i++ )
    {
        qDebug()<<"addr: "<<_destVector[i].addr<<"port: "<<_destVector[i].port;
    }
}

void H264Sender::delDest(QHostAddress addr, quint16 port)
{
    for ( int i=0; i<_destVector.size(); i++ )
    {
        if ( _destVector[i].addr == addr && _destVector[i].port == port )
        {
            _destVector.remove(i);
            qDebug()<<"remove addr: "<<addr<<"port: "<<port;
            break;
        }
    }
}

unsigned short H264Sender::htons(unsigned short data)
{
    unsigned char* p = (unsigned char*)&data;
    return ( (p[0]<<8) | (p[1]) );
}

unsigned int H264Sender::hton(unsigned int data)
{
    unsigned char* p = (unsigned char*)&data;
    return ( (p[0]<<24) | (p[1]<<16) | (p[2]<<8) | p[3] );
}

