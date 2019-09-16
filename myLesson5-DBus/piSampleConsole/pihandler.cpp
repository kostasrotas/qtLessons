#include "pihandler.h"
#include "QDebug"

PiHandler::PiHandler(QObject *parent) : QObject(parent)
{
    piPins = new org::example::kostasrotas::pipins("org.example.kostasrotas", "/PiPins",
                           QDBusConnection::sessionBus(), this);
}

void PiHandler::startReadTimer(){
     timerID=startTimer(1000);
}

void PiHandler::timerEvent(QTimerEvent *event){
    qDebug()<<"readPinValue";
    if (event->timerId()==timerID && piPins->isValid()){
        bool newValue=piPins->pinValue();
        if (newValue!=readPinValue){
            readPinValue=newValue;
            qDebug()<<"newPinValueFound: "<<readPinValue;
            emit readPinValueChanged();
        }
    }
}

void PiHandler::setWritePin(bool value){
    //readPinValue=value;
    //qDebug()<<"setPin: "<<readPinValue;
    //emit readPinValueChanged();
    if (!piPins->isValid())
        qDebug()<<"Not Connected";
    else
        emit piPins->setPin(value);
}
