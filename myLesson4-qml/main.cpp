#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include<qqmlcomponent.h>
#include "QDebug"

#include "phonemodel.h"

QObject *mainQmlComp;

void setTotalText(int i)
{
    mainQmlComp->setProperty("totalTextValue", i);
}

int main(int argc, char *argv[])
{
    //start phoneModel
    PhoneModel phoneModel;
    phoneModel.setStartData();
    phoneModel.addPersonData("Kostas","6977732555");
    phoneModel.addPersonData("Katerina","6977732666");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //Need these to expose phoneModel to qml
    qmlRegisterType<PhoneModel>("PhoneModel", 1, 0, "PhoneModel");    
    engine.rootContext()->setContextProperty("phoneModel", &phoneModel);

    //Start mail qml
    //engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    mainQmlComp = (new QQmlComponent (&engine, QUrl(QLatin1String("qrc:/main.qml"))))->create();

    phoneModel.updateCounter();

    return app.exec();
}
