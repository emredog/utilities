#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T11:14:27
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = NiUserTracker
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    opengles.cpp \
    SceneDrawer.cpp

HEADERS += \
    opengles.h \
    SceneDrawer.h \
    GL/gl.h \
    GL/glext.h \
    GL/glut.h \
    GL/wglext.h \
    GLES/egl.h \
    GLES/egl_1_0.h \
    GLES/egltypes.h \
    GLES/gl.h \
    GLES/gl_1_0.h \
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

INCLUDEPATH += /usr/include/ni

LIBS += -lOpenNI

LIBS += -LLibs -lglut -lGL

