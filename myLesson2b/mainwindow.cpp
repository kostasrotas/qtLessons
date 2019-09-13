#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *vb=new QVBoxLayout();
    vb->addWidget(lineEdit=new QLineEdit());
    vb->addWidget(pushButton=new QPushButton());
    pushButton->setText("Increase");
    setLayout(vb);
    QObject::connect(pushButton,SIGNAL(pressed()),this, SLOT(buttonPressed()));

}

MainWindow::~MainWindow()
{

}


void MainWindow::buttonPressed(){
    char str[256];
    int v=atol(lineEdit->text().toLatin1());
    sprintf(str,"%d",v+1);
    lineEdit->setText(str);
}
