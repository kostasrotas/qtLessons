#ifndef BALLWIDGET_H
#define BALLWIDGET_H

#include <QtWidgets>
#include "ballobject.h"

class BallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BallWidget(QWidget *parent = 0);
    BallObject * getBallObject();
    ~BallWidget();

signals:

public slots:
    void posChanged(int bpos);
    void paintEvent(QPaintEvent *event);

private:
    BallObject ballObject;
    int ballPos;
};

#endif // BALLWIDGET_H
