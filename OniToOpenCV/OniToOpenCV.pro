#-------------------------------------------------
#
# Project created by QtCreator 2015-02-06T11:52:48
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = OniToOpenCV
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    OniToOpenCV.cpp

INCLUDEPATH += /usr/include/ni

LIBS += -lopencv_core -lopencv_highgui -lOpenNI
