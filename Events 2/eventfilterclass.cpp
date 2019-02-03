#include "eventfilterclass.h"
#include <QEvent>

EventFilterClass::EventFilterClass(QObject *parent) : QObject(parent)
{

}

#include <QDebug>

bool EventFilterClass::eventFilter(QObject *watched, QEvent *event)
{
    if( event->type() == QEvent::KeyPress)
        qDebug() << "Key pressed";

    if( event->type() == QEvent::MouseButtonPress)
        qDebug() << "Mouse pressed";

    return false;
}
