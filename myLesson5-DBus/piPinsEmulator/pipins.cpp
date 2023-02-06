#include "pipins.h"

PiPins::PiPins(QObject *parent) : QObject(parent)
{
emuValue=false;
}

bool PiPins::pinValue() const{
    qDebug()<<"pinValue requested : ";
    return emuValue;
}

void PiPins::setPin(bool b){
    emuValue=b;
    qDebug()<<"setPin : "<<b;
}
