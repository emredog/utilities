#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T14:18:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MetersToRawDepth
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui
