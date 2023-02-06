#include <QCoreApplication>
#include <QDebug>
#include "pipins_adaptor.h"
#include "pipins.h"

int main(int argc, char *argv[])
{
    PiPins *piPins;
    QCoreApplication a(argc, argv);

    piPins= new PiPins();

    new PipinsAdaptor(piPins);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/PiPins", piPins);
    connection.registerService("org.example.kostasrotas");

    qDebug()<<"Emu Daemon started...";

    return a.exec();
}
