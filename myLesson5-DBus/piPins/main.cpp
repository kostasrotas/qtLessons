#include <QCoreApplication>
#include <QDebug>
#include "pipins_adaptor.h"
#include "pipins.h"

int main(int argc, char *argv[])
{
    PiPins *piPins;
    QCoreApplication a(argc, argv);

    qDebug()<<"Starting Raspberry Pi Pins Daemon...";
    piPins= new PiPins();

    new PipinsAdaptor(piPins);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/PiPins", piPins);
    connection.registerService("org.example.kostasrotas");


    return a.exec();
}
