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
    model/clientmodel.cpp \
    controler/staffcontroler.cpp \
    model/staffdao.cpp \
    staffview.cpp \
    model/c_init_bd.cpp \
    model/staffmodel.cpp

HEADERS  += mainwindow.h \
    authentificationdialog.h \
    model/authentificationmodel.h \
    views/createclientdialog.h \
    views/createstaffdialog.h \
    views/about.h \
    controler/clientcontroler.h \
    model/clientmodel.h \
    controler/staffcontroler.h \
    model/staffdao.h \
    staffview.h \
    model/c_init_bd.h \
    model/staffmodel.h

FORMS    += mainwindow.ui \
    authentificationdialog.ui \
    views/createclientdialog.ui \
    views/createstaffdialog.ui \
    views/about.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
