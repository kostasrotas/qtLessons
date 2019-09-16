#ifndef PIHANDLER_H
#define PIHANDLER_H

#include <QObject>

class PiHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool readPinValue MEMBER readPinValue NOTIFY readPinValueChanged)

    bool readPinValue;
public:
    explicit PiHandler(QObject *parent = nullptr);
    Q_INVOKABLE void setWritePin(bool value);


signals:
void readPinValueChanged();

public slots:
};

#endif // PIHANDLER_H
