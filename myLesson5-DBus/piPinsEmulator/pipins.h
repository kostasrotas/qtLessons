#ifndef PIPINS_H
#define PIPINS_H

#include <QObject>
#include <QDebug>

class PiPins : public QObject
{
    Q_OBJECT
public:
    explicit PiPins(QObject *parent = nullptr);

    Q_PROPERTY(bool pinValue READ pinValue)
    bool pinValue() const;
signals:

public slots:
    void setPin(bool b);

private:
    bool emuValue;
};

#endif // PIPINS_H
