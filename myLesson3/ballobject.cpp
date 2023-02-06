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
    timerID=startTimer(100);
}

void BallObject::startBall(){
    if (speed==0 && ballPos==0)
        speed=startSpeed;
    qDebug()<<"startBall received :"<<speed;
    qDebug()<<QObject::sender()->property("myValue");
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
