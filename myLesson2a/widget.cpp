#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(pressed()),this, SLOT(buttonPressed()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::buttonPressed(){
    char str[256];
    int v=atol(ui->lineEdit->text().toLatin1());
    sprintf(str,"%d",v+1);
    ui->lineEdit->setText(str);
}

