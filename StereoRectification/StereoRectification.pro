#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T17:21:48
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = StereoRectification
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    stereo_match.cpp

LIBS += -lopencv_core -lopencv_calib3d -lopencv_imgproc -lopencv_highgui -lopencv_contrib
