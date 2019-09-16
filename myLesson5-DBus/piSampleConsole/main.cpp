#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <qqmlcomponent.h>

#include "pihandler.h"

int main(int argc, char *argv[])
{

    PiHandler piHandler;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    qmlRegisterType<PiHandler>("PiHandler", 1, 0, "PiHandler");
    engine.rootContext()->setContextProperty("piHandler", &piHandler);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    piHandler.startReadTimer();

    return app.exec();
}
