#ifndef COUNTER_H
#define COUNTER_H

#include <QtCore>


class Counter : public QObject{
    Q_OBJECT
public:
    Counter();
    int value() const;
public slots:
    void setValue(int value);
signals:
    void valueChanged(int newValue);
private:
    int m_value;
};

#endif // COUNTER_H
