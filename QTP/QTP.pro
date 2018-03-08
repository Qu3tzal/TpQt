#-------------------------------------------------
#
# Project created by QtCreator 2018-02-09T17:23:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    authentificationdialog.cpp \
    model/authentificationmodel.cpp \
    views/createclientdialog.cpp \
    views/createstaffdialog.cpp \
    views/about.cpp \
    controler/clientcontroler.cpp \
    controler/staffcontoler.cpp \
    model/clientmodel.cpp \
    model/staffmodel.cpp

HEADERS  += mainwindow.h \
    authentificationdialog.h \
    model/authentificationmodel.h \
    views/createclientdialog.h \
    views/createstaffdialog.h \
    views/about.h \
    controler/clientcontroler.h \
    controler/staffcontoler.h \
    model/clientmodel.h \
    model/staffmodel.h

FORMS    += mainwindow.ui \
    authentificationdialog.ui \
    views/createclientdialog.ui \
    views/createstaffdialog.ui \
    views/about.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
