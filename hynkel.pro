#-------------------------------------------------
#
# Project created by QtCreator 2014-09-15T14:04:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hynkel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lib.cpp \
    naukaform.cpp \
    plik_testu/plik_testu.cpp

HEADERS  += mainwindow.h \
    lib.h \
    naukaform.h \
    plik_testu/plik_testu.h

FORMS    += mainwindow.ui \
    naukaform.ui
