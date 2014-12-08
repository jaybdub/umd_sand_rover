#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T04:20:49
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisionSystem2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    serialportwidget.cpp \
    serialportlistwidget.cpp \
    marker.cpp \
    pose.cpp

HEADERS  += mainwindow.h\
    serialportwidget.h \
    serialportlistwidget.h \
    marker.h \
    pose.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

unix|win32: LIBS += -L/usr/local/lib -laruco -lopencv_highgui -lopencv_core

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
