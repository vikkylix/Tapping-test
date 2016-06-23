#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T12:51:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TappingTest
TEMPLATE = app

#SUBDIRS = Admin Auth Expert Graphics Instruction Prepod Reports Results Spravka Student TappingTest\
#Admin\
#Auth\
#Expert\
#Graphics\
#Instruction\
#Prepod\
#Reports\
#Results\
#Spravka\
#Student\
#TappingTest

SOURCES += Admin/admin.cpp \
    Admin/adminadd.cpp \
    Admin/admindelete.cpp \
    Auth/mainwindow.cpp \
    Expert/expert.cpp \
    Graphics/grafikpnv.cpp \
    Graphics/grafikpv.cpp \
    Graphics/grafikss.cpp \
    Graphics/graphiksnv.cpp \
    Graphics/graphikss.cpp \
    Graphics/graphiksv.cpp \
    Instruction/instuctionstud.cpp \
    Prepod/prepodmain.cpp \
    Prepod/prepodrekkom.cpp \
    Prepod/prepodrez.cpp \
    Reports/zagruzkaotch.cpp \
    Results/rezteststud.cpp \
    Spravka/spravka.cpp \
    Student/stud.cpp \
    TappingTest/teppingtest.cpp \
    main.cpp

HEADERS  += Admin/admin.h \
    Admin/adminadd.h \
    Admin/admindelete.h \
    Auth/mainwindow.h \
    Expert/expert.h \
    Graphics/grafikpnv.h \
    Graphics/grafikpv.h \
    Graphics/grafikss.h \
    Graphics/graphiksnv.h \
    Graphics/graphikss.h \
    Graphics/graphiksv.h \
    Instruction/instuctionstud.h \
    Prepod/prepodmain.h \
    Prepod/prepodrekkom.h \
    Prepod/prepodrez.h \
    Reports/zagruzkaotch.h \
    Results/rezteststud.h \
    Spravka/spravka.h \
    Student/stud.h \
    TappingTest/teppingtest.h

FORMS    += Admin/admin.ui \
    Admin/adminadd.ui \
    Admin/admindelete.ui \
    Auth/mainwindow.ui \
    Expert/expert.ui \
    Graphics/grafikpnv.ui \
    Graphics/grafikpv.ui \
    Graphics/grafikss.ui \
    Graphics/graphiksnv.ui \
    Graphics/graphikss.ui \
    Graphics/graphiksv.ui \
    Instruction/instuctionstud.ui \
    Prepod/prepodmain.ui \
    Prepod/prepodrekkom.ui \
    Prepod/prepodrez.ui \
    Reports/zagruzkaotch.ui \
    Results/rezteststud.ui \
    Spravka/spravka.ui \
    Student/stud.ui \
    TappingTest/teppingtest.ui
QT += axcontainer
CONFIG += qwt
INCLUDEPATH += C:/qwt-6.1.2/include

LIBS += -LC:/qwt-6.1.2/lib -lqwt
