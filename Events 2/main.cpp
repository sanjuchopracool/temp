#include <QQuickView>
#include <QApplication>
#include <eventfilterclass.h>
#include "customquickview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EventFilterClass filter;
    a.installEventFilter(&filter);
    CustomQuickView w;
    w.setFlag(Qt::WindowStaysOnTopHint);
    w.setSource(QUrl("qrc:/Hello.qml"));
    w.show();

    return a.exec();
}
