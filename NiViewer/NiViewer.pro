#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T17:18:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = NiViewer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/include/ni

LIBS += -lOpenNI -lglut -lGL


SOURCES += \
    Audio.cpp \
    Capture.cpp \
    Device.cpp \
    Draw.cpp \
    Keyboard.cpp \
    Menu.cpp \
    MouseInput.cpp \
    NiViewer.cpp \
    Statistics.cpp

HEADERS += \
    Audio.h \
    Capture.h \
    Device.h \
    Draw.h \
    Keyboard.h \
    Menu.h \
    MouseInput.h \
    Statistics.h \
    GL/gl.h \
    GL/glext.h \
    GL/glut.h \
    GL/wglext.h \
    glh/glh_array.h \
    glh/glh_convenience.h \
    glh/glh_cube_map.h \
    glh/glh_extensions.h \
    glh/glh_genext.h \
    glh/glh_glut.h \
    glh/glh_glut2.h \
    glh/glh_glut_callfunc.h \
    glh/glh_glut_replay.h \
    glh/glh_glut_text.h \
    glh/glh_interactors.h \
    glh/glh_linear.h \
    glh/glh_mipmaps.h \
    glh/glh_obs.h \
    glh/glh_text.h

OTHER_FILES += \
    Libs/glut32.lib \
    Libs/glut64.lib
