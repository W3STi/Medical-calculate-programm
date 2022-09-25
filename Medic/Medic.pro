QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form1.cpp \
    form2.cpp \
    form3.cpp \
    form4.cpp \
    form5.cpp \
    form6.cpp \
    form7.cpp \
    form8.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    form1.h \
    form2.h \
    form3.h \
    form4.h \
    form5.h \
    form6.h \
    form7.h \
    form8.h \
    mainwindow.h

FORMS += \
    form1.ui \
    form2.ui \
    form3.ui \
    form4.ui \
    form5.ui \
    form6.ui \
    form7.ui \
    form8.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
