#include "customgraphicsview.h"

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QApplication>

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing, true);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//    setDragMode(QGraphicsView::ScrollHandDrag);

    QGraphicsScene * scene = new QGraphicsScene(this);
    scene->setSceneRect(-2000, -2000, 4000, 4000);
    auto rect = new QGraphicsRectItem(0, 0, 500, 500);
    rect->setBrush(Qt::red);
    auto circle = new QGraphicsEllipseItem(245, 245, 10, 10);
    circle->setBrush(Qt::cyan);
    scene->addItem(rect);
    scene->addItem(circle);
    setScene(scene);
    QApplication::setStartDragDistance(4);
}

CustomGraphicsView::~CustomGraphicsView()
{

}

#include <QDebug>
void CustomGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier)
    {
        // zoom
        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        int angle = event->angleDelta().y();
        qreal factor;
        if (angle > 0) {
            factor = 1.1;
        } else {
            factor = 1/1.1;
        }
        scale(factor, factor);
        qWarning() << "zoom";
        setTransformationAnchor(anchor);
        event->accept();
    }
    else
    {
        QGraphicsView::wheelEvent(event);
    }
}

#include <QApplication>
void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton &&
            event->modifiers() == Qt::NoModifier )
    {
        panning = true;
        lastPos = event->pos();
        event->accept();
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
    }
    else
    {
        QGraphicsView::mousePressEvent(event);
    }
}

void CustomGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton)
    {
        panning = false;
        QApplication::restoreOverrideCursor();
        event->accept();
    }
    else
    {
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (panning && event->button() == Qt::MiddleButton &&
            event->modifiers() == Qt::NoModifier )
    {
        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::NoAnchor);
        QPoint newPos = event->pos();
        qWarning() << "Mouse move " << (newPos - lastPos);
//        QPointF movement = (newPos) - (lastPos);
        QPointF movement = mapToScene(newPos) - mapToScene(lastPos);
//        QPointF movement = mapFromScene(newPos) - mapFromScene(lastPos);
        lastPos = newPos;
//        auto tran = viewportTransform();
//        qWarning() << tran.m11();
        qWarning() << "Translation " << movement;
//        translate(movement.x(), movement.y());
//        setTransform(QTransform::fromTranslate(movement.x(),
//                                               movement.y()),
//                     true);
        qreal x = movement.x();
        qreal y = movement.y();
        translate(x, y);
        event->accept();
        setTransformationAnchor(anchor);
    }
    else
    {
        QGraphicsView::mouseMoveEvent(event);
    }
}
