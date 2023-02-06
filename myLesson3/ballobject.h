#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <QObject>

class BallObject : public QObject
{
    Q_OBJECT

public:
    explicit BallObject(QObject *parent);

signals:
    void posChanged(int newPos);

public slots:
    void startBall();
    void changeStartSpeed(int);
    void timerEvent(QTimerEvent *event);

private:
    int timerID;
    int startSpeed,speed,ballPos;
};

#endif // BALLOBJECT_H

