#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(2,16);
    ui->pushButton->setProperty("myValue","a Value");
    QObject::connect(ui->pushButton,SIGNAL(pressed()),ui->widget,SLOT(startBall()));
    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(changeStartSpeed(int)));
    ui->horizontalSlider->setValue(15);
}

Widget::~Widget()
{
    delete ui;
}
