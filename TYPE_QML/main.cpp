#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "SettingManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterUncreatableType<Setting>("com.sanjay.setting", 1, 0, "Setting", "can not create Setting type object");

    SettingManager manager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("SettingManager",&manager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
