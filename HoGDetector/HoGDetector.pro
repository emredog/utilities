#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:16:28
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = HoGDetector
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
LIBS += -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc
