#-------------------------------------------------
#
# Project created by QtCreator 2020-11-07T10:49:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VtoVSimulation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mapopengl.cpp \
    Modele/Car.cpp \
    Modele/Clock.cpp \
    Modele/Hexagon.cpp \
    Modele/Mapping.cpp \
    Modele/Mesh.cpp \
    Modele/MeshLines.cpp \
    Modele/Node.cpp \
    Modele/Point.cpp \
    Modele/Simulation.cpp \
    Modele/Wave.cpp \
    Modele/Way.cpp

HEADERS += \
        mainwindow.h \
    mapopengl.h \
    Modele/Car.h \
    Modele/Clock.h \
    Modele/Hexagon.h \
    Modele/Mapping.h \
    Modele/Mesh.h \
    Modele/MeshLines.h \
    Modele/Node.h \
    Modele/Point.h \
    Modele/Simulation.h \
    Modele/Wave.h \
    Modele/Way.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    Modele/MainTestCar.txt
