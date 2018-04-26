#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T18:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ssf
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    core.cpp \
    screenwelcome.cpp \
    task.cpp \
    screenabout.cpp \
    screendescription.cpp \
    screenquestion.cpp \
    questionanswerlabel.cpp \
    static.cpp \
    screensummary.cpp \
    question.cpp \
    view/clickableqlabel.cpp \
    task/screentask1.cpp \
    task/screentask2.cpp \
    task/screentask3.cpp \
    task/screentask4.cpp \
    task/screentask5.cpp \
    task/screentask6.cpp \
    task/screentask7.cpp \
    task/screentask8.cpp \
    task/screentask9.cpp \
    screencontroller.cpp \
    task/screentask10.cpp

HEADERS += \
        mainwindow.h \
    windowcontroller.h \
    task.h \
    screenwelcome.h \
    core.h \
    screenabout.h \
    screendescription.h \
    screenquestion.h \
    questionanswerlabel.h \
    static.h \
    screensummary.h \
    question.h \
    view/clickableqlabel.h \
    task/screentask1.h \
    screencontroller.h \
    task/screentask2.h \
    task/screentask3.h \
    task/screentask4.h \
    task/screentask5.h \
    task/screentask6.h \
    task/screentask7.h \
    task/screentask8.h \
    task/screentask9.h \
    task/screentask10.h

FORMS += \
        mainwindow.ui \
    screenwelcome.ui \
    screenabout.ui \
    screendescription.ui \
    screenquestion.ui \
    screensummary.ui \
    task/screentask1.ui \
    task/screentask2.ui \
    task/screentask3.ui \
    task/screentask4.ui \
    task/screentask5.ui \
    task/screentask6.ui \
    task/screentask7.ui \
    task/screentask8.ui \
    task/screentask9.ui \
    task/screentask10.ui

RESOURCES += \
    resources.qrc
