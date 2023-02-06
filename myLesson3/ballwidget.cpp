#include "ballwidget.h"


BallWidget::BallWidget(QWidget *parent) : QWidget(parent),ballObject(nullptr){
    QObject::connect(&ballObject,SIGNAL(posChanged(int)),this,SLOT(posChanged(int)));
}

BallObject *BallWidget::getBallObject()
{
    return &ballObject;
}

BallWidget::~BallWidget()
{

}

void BallWidget::posChanged(int bPos)
{
    ballPos=bPos;
    update();
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
