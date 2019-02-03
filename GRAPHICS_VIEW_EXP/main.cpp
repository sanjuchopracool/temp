#include "customgraphicsview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomGraphicsView w;
    w.show();

    return a.exec();
}
