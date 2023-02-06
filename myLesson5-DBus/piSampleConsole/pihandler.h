#ifndef PIHANDLER_H
#define PIHANDLER_H

#include <QObject>
#include "pipins_interface.h"

class PiHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool readPinValue MEMBER readPinValue NOTIFY readPinValueChanged)

    bool readPinValue;
public:
    explicit PiHandler(QObject *parent = nullptr);
    Q_INVOKABLE void setWritePin(bool value);    
    void startReadTimer();

signals:
void readPinValueChanged();

public slots:
    void timerEvent(QTimerEvent *event);

private:
    org::example::kostasrotas::pipins *piPins;
    int timerID;
};

#endif // PIHANDLER_H
