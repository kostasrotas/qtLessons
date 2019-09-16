#include "pipins.h"
#include "QProcess"

PiPins::PiPins(QObject *parent) : QObject(parent){
    QProcess p;
    p.setStandardOutputFile("/sys/class/gpio/export");
    p.start("echo",QStringList()<<"11");
    p.waitForFinished();
    p.setStandardOutputFile("/sys/class/gpio/gpio11/direction");
    p.start("echo",QStringList()<<"out");
    p.waitForFinished();
    p.setStandardOutputFile("/sys/class/gpio/export");
    p.start("echo",QStringList()<<"9");
    p.waitForFinished();
    p.setStandardOutputFile("/sys/class/gpio/gpio11/direction");
    p.start("echo",QStringList()<<"in");
    p.waitForFinished();
}

bool PiPins::pinValue() const{
    qDebug()<<"pinValue requested : ";
    QProcess p;
    p.start("cat",QStringList()<<"/sys/class/gpio/gpio9/value");
    p.waitForFinished();
    if (p.readAllStandardOutput()[0]=='0')
        return false;
    else
        return true;
}

void PiPins::setPin(bool b){
    qDebug()<<"setPin : "<<b;
    QProcess p;
    p.setStandardOutputFile("/sys/class/gpio/gpio11/value");
    p.start("echo",QStringList()<<(b?"1":"0"));
    p.waitForFinished();
}
