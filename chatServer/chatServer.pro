QT += core
QT -= gui

CONFIG += c++11

TARGET = chatServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    serversocket.cpp \
    chatserver.cpp \
    ../socket.cpp

HEADERS += \
    serversocket.h \
    ../socketexception.h \
    ../socket.h


