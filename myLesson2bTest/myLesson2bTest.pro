QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_mylesson2btest.cpp \
    ../myLesson2b/mainwindow.cpp

HEADERS += \
    ../myLesson2b/mainwindow.h
