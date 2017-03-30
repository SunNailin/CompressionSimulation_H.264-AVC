#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QImage>

namespace Ui {
class videoWidget;
}

class videoWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit videoWidget(QWidget *parent = 0);
    ~videoWidget();
    void setImg(QImage img);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::videoWidget *ui;
    QImage m_img;
};

#endif // VIDEOWIDGET_H
