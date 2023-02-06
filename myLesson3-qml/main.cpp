#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include<qqmlcomponent.h>

#include "ballobject.h"


int main(int argc, char *argv[])
{
    BallObject ballObject(nullptr);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<BallObject>("BallObject", 1, 0, "BallObject");
    engine.rootContext()->setContextProperty("ballObject", &ballObject);

    const QUrl url(u"qrc:/myLesson3-qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
