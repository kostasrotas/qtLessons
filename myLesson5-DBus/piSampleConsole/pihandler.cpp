#include "pihandler.h"
#include "QDebug"

PiHandler::PiHandler(QObject *parent) : QObject(parent)
{

}

void PiHandler::setWritePin(bool value){
    readPinValue=value;
    qDebug()<<"setPin: "<<readPinValue;
    emit readPinValueChanged();
}
