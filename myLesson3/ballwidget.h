#ifndef BALLWIDGET_H
#define BALLWIDGET_H

#include <QtWidgets>

class BallWidget : public QWidget
{
    int timerID;
    int startSpeed,speed,ballPos;
    Q_OBJECT
public:
    explicit BallWidget(QWidget *parent = 0);
    ~BallWidget();

signals:

public slots:
    void startBall();
    void changeStartSpeed(int);
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // BALLWIDGET_H
