#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>

class MainWindow : public QWidget
{

friend class MainWindowTest;

    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonPressed();

private:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
};

#endif // MAINWINDOW_H
