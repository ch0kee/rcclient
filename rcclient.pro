#-------------------------------------------------
#
# Project created by QtCreator 2012-08-19T02:24:16
#
#-------------------------------------------------

QT       += core

QT       -= gui


TARGET = rcclient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lboost_system -lboost_filesystem

SOURCES += main.cpp
