#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <QObject>

class BallObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int pressCounter READ getPressCounter NOTIFY pressCounterChanged)
    //Q_PROPERTY(int pressCounter MEMBER pressCounter NOTIFY pressCounterChanged)

public:
    explicit BallObject(QObject *parent);    
    int getPressCounter();

signals:
    void posChanged(int newPos);
    void pressCounterChanged();

public slots:
    void startBall();
    void changeStartSpeed(int);
    void timerEvent(QTimerEvent *event);


private:
    int timerID;
    int startSpeed,speed,ballPos;
    int pressCounter;
};

#endif // BALLOBJECT_H

