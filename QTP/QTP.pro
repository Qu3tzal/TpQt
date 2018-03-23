#-------------------------------------------------
#
# Project created by QtCreator 2018-02-09T17:23:41
#
#-------------------------------------------------

QT       += core gui sql

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
    model/clientmodel.cpp \
    model/databasecreator.cpp \
    model/staff.cpp \
    views/staffview.cpp \
    model/staffmodel.cpp \
    model/account.cpp \
    model/accountmodel.cpp \
    views/clientview.cpp \
    model/client.cpp \
    model/appointmentscheduler.cpp \
    model/appointmentmodel.cpp \
    model/appointment.cpp

HEADERS  += mainwindow.h \
    authentificationdialog.h \
    model/authentificationmodel.h \
    views/createclientdialog.h \
    views/createstaffdialog.h \
    views/about.h \
    model/clientmodel.h \
    model/databasecreator.h \
    model/staff.h \
    views/staffview.h \
    model/staffmodel.h \
    model/account.h \
    model/accountmodel.h \
    views/clientview.h \
    model/client.h \
    model/appointmentscheduler.h \
    model/appointmentmodel.h \
    model/appointment.h

FORMS    += mainwindow.ui \
    authentificationdialog.ui \
    views/createclientdialog.ui \
    views/createstaffdialog.ui \
    views/about.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
