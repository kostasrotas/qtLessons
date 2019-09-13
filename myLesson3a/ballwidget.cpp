#include "ballwidget.h"


BallWidget::BallWidget(QWidget *parent) : QWidget(parent){    
    startSpeed=15;
    ballPos=0;
    speed=0;
    timerID=startTimer(100);
}

BallWidget::~BallWidget()
{

}

void BallWidget::startBall(){
    if (speed==0 && ballPos==0)
        speed=startSpeed;
    qDebug()<<"startBall received :"<<speed;
    qDebug()<<QObject::sender()->property("myValue");
}


void BallWidget::changeStartSpeed(int newvalue){
    startSpeed=newvalue;
}


void BallWidget::timerEvent(QTimerEvent *event){
    if (event->timerId()==timerID){
        ballPos+=speed--;
        if (ballPos<=0){
            speed=0;
            ballPos=0;
        }
        repaint();
    }
}

void BallWidget::paintEvent(QPaintEvent *event){
    QPainter painter;
    QColor color;
    painter.begin(this);
    color.setRgb(120,15,15);
    painter.setPen(QPen(color,1));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(100,130-ballPos,13,13);
    color.setRgb(0,100,0);
    painter.setPen(QPen(color,1));
    painter.drawLine(70,143,150,143);
    painter.end();
}
