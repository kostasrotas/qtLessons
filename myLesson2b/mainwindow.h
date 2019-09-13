#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>

class MainWindow : public QWidget
{

    QLineEdit *lineEdit;
    QPushButton *pushButton;

    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonPressed();
};

#endif // MAINWINDOW_H
