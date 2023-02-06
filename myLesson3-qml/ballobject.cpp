#include "ballobject.h"
#include "QDebug"
#include "QVariant"
#include "QTimerEvent"

BallObject::BallObject(QObject *parent)
    : QObject(parent)
{    
    startSpeed=15;
    ballPos=0;
    speed=0;
    timerID=-1;
    pressCounter=0;
}

void BallObject::startBall(){
    if (timerID==-1)
        timerID=startTimer(100);
    if (speed==0 && ballPos==0){
        speed=startSpeed;
        pressCounter++;
        emit pressCounterChanged();
    }
    qDebug()<<"startBall received :"<<speed;
    //qDebug()<<QObject::sender()->property("myValue");
}


void BallObject::changeStartSpeed(int newvalue){
    startSpeed=newvalue;
}


void BallObject::timerEvent(QTimerEvent *event){
    if (event->timerId()==timerID){
        ballPos+=speed--;
        if (ballPos<=0){
            speed=0;
            ballPos=0;
        }
        emit posChanged(ballPos);
    }
}

int BallObject::getPressCounter()
{
    qDebug()<<"getPressCounter received !";
    return pressCounter;
}
