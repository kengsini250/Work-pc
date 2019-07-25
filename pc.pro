######################################################################
# Automatically generated by qmake (3.1) Tue Jul 16 16:12:39 2019
######################################################################

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = pc
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
CONFIG += c++11

HEADERS += head/dataformat.h \
           head/Products/productB.h \
           head/mainwindow.h \
           head/product_factory.h \
           head/server.h \
           head/Products/productA.h \
           head/Products_Base/ui_main_class.h
FORMS += ui/mainwindow.ui ui/UI_Temp.ui ui/Products/productA.ui \
    ui/Products/productB.ui
SOURCES += main.cpp \
           cpp/Products/productB.cpp \
           cpp/mainwindow.cpp \
           cpp/server.cpp \
           cpp/Products/productA.cpp \
           cpp/Products_Base/ui_main_class.cpp
