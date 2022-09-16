#include <QtTest>
#include <QCoreApplication>
#include "../myLesson2b/mainwindow.h"

// add necessary includes here

class MainWindowTest: public MainWindow{
public:
    QString getText(){
        return lineEdit->text();
    }

    void setText(QString s){
        lineEdit->setText(s);
    }

    QPushButton * getButton(){
        return pushButton;
    }

};

class myLesson2bTest : public QObject
{
    Q_OBJECT
MainWindowTest *wp;
public:
    myLesson2bTest();
    ~myLesson2bTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();

};

myLesson2bTest::myLesson2bTest()
{

}

myLesson2bTest::~myLesson2bTest()
{

}

void myLesson2bTest::initTestCase()
{
wp = new MainWindowTest();
wp->show();
}

void myLesson2bTest::cleanupTestCase()
{
    wp->close();
}

void myLesson2bTest::test_case1()
{
wp->setText("100");
emit wp->getButton()->pressed();
QCOMPARE(wp->getText(),"101");
}

void myLesson2bTest::test_case2()
{
    wp->setText("");
    emit wp->getButton()->pressed();
QVERIFY(wp->getText() == "1");
}

QTEST_MAIN(myLesson2bTest)

#include "tst_mylesson2btest.moc"
