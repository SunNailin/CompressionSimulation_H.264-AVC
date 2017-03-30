#include "videowidget.h"
#include "ui_videowidget.h"

videoWidget::videoWidget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::videoWidget)
{
    ui->setupUi(this);
}

videoWidget::~videoWidget()
{
    delete ui;
}

void videoWidget::setImg(QImage img)
{
    m_img = img;
}

void videoWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if ( m_img.width() > 0 )
    {
        painter.drawImage(this->rect(), m_img);
    }
}
