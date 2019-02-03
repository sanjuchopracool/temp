#include "widget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
}

Widget::~Widget()
{
}

QSize Widget::sizeHint() const
{
    return QSize(600, 400);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QSize wSize = size();
    qDebug() << wSize;

    painter.translate(wSize.width()/2, wSize.height()/2);


    QSize rectSize = wSize/2;
    int rWidth = rectSize.width();
    int rHeight = rectSize.height();

    // move to position
    painter.translate(-rWidth/2, rHeight/2);

    // move to pivot point
    QPoint p(-rWidth/2, rHeight/2);
    painter.translate(p);

    //rotation
    painter.rotate(45);
    // scale
    painter.scale(0.5, 0.5);

    // move back to origional point
    painter.translate(-p);

    qDebug() << rectSize;
    // draw rect in , assume current point as center
    painter.setBrush(Qt::darkCyan);
    painter.drawRect(QRect(-rectSize.width()/2, -rectSize.height()/2,
                           rectSize.width(), rectSize.height()));
}
