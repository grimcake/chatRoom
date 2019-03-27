QT += core
QT -= gui

CONFIG += c++11

TARGET = chatClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    clientsocket.cpp \
    chatclient.cpp \
    ../socket.cpp

HEADERS += \
    clientsocket.h \
    ../socketexception.h \
    ../socket.h
