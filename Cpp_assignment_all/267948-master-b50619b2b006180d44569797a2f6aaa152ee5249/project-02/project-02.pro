QT += core
QT -= gui

CONFIG += c++11

TARGET = practice1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    splitter.cpp \
    read_and_store.cpp \
    query.cpp

HEADERS += \
    splitter.h \
    read_and_store.h \
    query.h
