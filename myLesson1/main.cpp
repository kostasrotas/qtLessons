
#include <QtCore>
#include "counter.h"



Counter::Counter() { m_value = 0; }

int Counter::value() const { return m_value; }

void Counter::setValue(int value){
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}



int main(int argc, char *argv[]){
    //QCoreApplication application(argc, argv);
    Counter a, b;

    QObject::connect(&b, SIGNAL(valueChanged(int)),&a, SLOT(setValue(int)));
    a.setValue(12);     // a.value() == 12,
    b.setValue(48);     // a.value() == 48, b.value() == 48
    printf("a = %d\nb = %d\n",a.value(),b.value());
    //return application.exec();
}
