#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T17:25:33
#
#-------------------------------------------------

QT       += core gui serialport printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeytrackSimple
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    keytrackmarkertrajectory.cpp \
    keytrackmarkertrajectorylist.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    keytrackmarkertrajectory.h \
    keytrackmarkertrajectorylist.h

FORMS    += mainwindow.ui



#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../aruco-1.2.4/build/src/release/ -laruco
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../aruco-1.2.4/build/src/debug/ -laruco
#else:unix: LIBS += -L$$PWD/../../../aruco-1.2.4/build/src/ -laruco

#INCLUDEPATH += $$PWD/../../../aruco-1.2.4/src
#DEPENDPATH += $$PWD/../../../aruco-1.2.4/src

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lopencv_core
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lopencv_core
#else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lopencv_core

#INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
#DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lopencv_highgui
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lopencv_highgui
#else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lopencv_highgui

#INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
#DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

unix|win32: LIBS += -L/usr/local/lib -laruco -lopencv_highgui -lopencv_core

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
