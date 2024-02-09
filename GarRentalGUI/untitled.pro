QT       += core gui

QT += sql

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcarswindow.cpp \
    addcustomerwindow.cpp \
    addwindow.cpp \
    editcarwindow.cpp \
    editcustomerwindow.cpp \
    editorremovewindow.cpp \
    findcar.cpp \
    findcustomer.cpp \
    main.cpp \
    mainwindow.cpp\
    databasemanager.cpp \
    removecarwindow.cpp \
    removecustomerwindow.cpp \
    filemanager.cpp


HEADERS += \
    addcarswindow.h \
    addcustomerwindow.h \
    addwindow.h \
    editcarwindow.h \
    editcustomerwindow.h \
    editorremovewindow.h \
    findcar.h \
    findcustomer.h \
    mainwindow.h\
    databasemanager.h\
    data_defs.h \
    removecarwindow.h \
    removecustomerwindow.h \
    converter.h \
    filemanager.h

FORMS += \
    addcarswindow.ui \
    addcustomerwindow.ui \
    addwindow.ui \
    editcarwindow.ui \
    editcustomerwindow.ui \
    editorremovewindow.ui \
    findcar.ui \
    findcustomer.ui \
    mainwindow.ui \
    removecarwindow.ui \
    removecustomerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
