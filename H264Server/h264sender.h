#ifndef H264SENDER_H
#define H264SENDER_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QByteArray>
#include <QThread>

#define MAXSIZE 1400

// RTP header
struct RtpHeader
{
    // byte 1
    unsigned char cc:4;     // CSRC count
    unsigned char x:1;      // extension
    unsigned char p:1;      // padding
    unsigned char v:2;      // version

    // byte 2
    unsigned char pt:7;     // payload type
    unsigned char m:1;      // marker

    // byte 3,4
    unsigned short seqnum;  // sequence number

    // byte 5~8
    unsigned int timestamp; // timestamp

    // byte 9~12
    unsigned int ssrc;      // SSRC
};

// nalu and FU-indicator
struct NaluHeader
{
    unsigned char type:5;   // type 28 is FU-A, type 29 is FU-B see rfc3984 for more info
    unsigned char nri:2;
    unsigned char f:1;
};

// FU header
struct FuHeader
{
    unsigned char type:5;
    unsigned char r:1;      // start bit
    unsigned char e:1;      // end bit
    unsigned char s:1;      // reserve bit
};

struct Destination
{
    QHostAddress addr;
    quint16 port;
};

class H264Sender : public QObject
{
    Q_OBJECT
public:
    explicit H264Sender(QObject *parent = 0);
    ~H264Sender();

public:
    int sendPacket(char* buf, int size, unsigned int timeIncrease);
    int destNumber();
    void clean();

signals:

public slots:
    void addDest(QHostAddress addr, quint16 port);
    void delDest(QHostAddress addr, quint16 port);

private:
    unsigned short htons(unsigned short data);
    unsigned int hton(unsigned int data);

private:
    RtpHeader _rtpHeader;
    NaluHeader _naluHead;
    unsigned short _seqNumber;
    unsigned int _timestamp;
    QUdpSocket* _udpSocket;
    QVector<Destination> _destVector;
};

#endif // H264SENDER_H
