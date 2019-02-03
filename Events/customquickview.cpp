#include "customquickview.h"

CustomQuickView::CustomQuickView(QWindow *parent)
    : QQuickView(parent)
{
    connect(this, SIGNAL(activeChanged()), this, SLOT(onActivateChanged()));
}

#include <QDebug>
void CustomQuickView::onActivateChanged()
{
    if(!isActive())
    {
        qDebug() << "Not activated, requesting activate";
//        requestActivate();
//        setWindowState(Qt::WindowActive);
        raise();
        requestActivate();
    }
}
