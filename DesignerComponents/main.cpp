#include "widget.h"
#include <QApplication>

#include <qdesigner_components.h>
#include <QDesignerWidgetBoxInterface>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    auto interface = QDesignerComponents::createFormEditor(&w);
    auto widgetBox = QDesignerComponents::createWidgetBox(interface, &w);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(widgetBox);
    w.setLayout(layout);

    w.show();

    return a.exec();
}
