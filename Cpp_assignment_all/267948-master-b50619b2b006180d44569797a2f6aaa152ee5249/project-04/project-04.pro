QT += core
QT -= gui

CONFIG += c++11

TARGET = project-04
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    p_queue.cpp \
    function_chores.cpp

HEADERS += \
    p_queue.h \
    function_chores.h
