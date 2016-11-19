#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T15:53:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iyzipay-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    options.cpp \
    iyzipayresource.cpp \
    request.cpp \
    hashgenerator.cpp \
    httpclient.cpp \
    retrievebinnumberrequest.cpp \
    binnumber.cpp \
    apitest.cpp

HEADERS  += mainwindow.h \
    options.h \
    iyzipayresource.h \
    request.h \
    hashgenerator.h \
    httpclient.h \
    httpmethod.h \
    randomstringutility.h \
    retrievebinnumberrequest.h \
    binnumber.h \
    apitest.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/qjson
LIBS += -L/usr/lib -lqjson



