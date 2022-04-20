#-------------------------------------------------
#
# Project created by QtCreator 2010-10-08T12:56:49
#
#-------------------------------------------------

QT       += core gui opengl glut

TARGET = Env_convexe_interface
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    gl_widget.cpp \
    Trackball.cpp \
    Vec_4D.cpp \
    Sommet_hyp_aff.cpp \
    Hypercube_aff.cpp \
    Env_convexe/Sommet.cpp \
    Env_convexe/hypercube.cpp \
    Env_convexe/Face.cpp \
    Env_convexe/Exception.cpp \
    Env_convexe/Env_convexe.cpp \
    Env_convexe/Cube.cpp \
    Env_convexe/Arrete.cpp \
    Widget_New_Hyp.cpp \
    dual_quaternion.cpp \
    Thread_Creer_Config.cpp \
    dialog_choix_fichier.cpp \
    version.cpp \
    mainwindow.cpp

HEADERS  += widget.h \
    gl_widget.h \
    Trackball.h \
    Hypercube_aff.h \
    Sommet_hyp_aff.h \
    Vec_4D.h \
    Env_convexe/Sommet.h \
    Env_convexe/hypercube.h \
    Env_convexe/Header_general.h \
    Env_convexe/Face.h \
    Env_convexe/Exception.h \
    Env_convexe/Env_convexe.h \
    Env_convexe/Cube.h \
    Env_convexe/Constant_project.h \
    Env_convexe/Arrete.h \
    Widget_New_Hyp.h \
    Dual_quaternion.h \
    Thread_Creer_Config.h \
    dialog_choix_fichier.h \
    version.h \
    mainwindow.h

FORMS    += \
    dialog_choix_fichier.ui \
    version.ui \
    mainwindow.ui

RESOURCES += \
    ressource.qrc
