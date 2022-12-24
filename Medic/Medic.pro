QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forms/src/helloform.cpp \
    forms/src/conclusion.cpp \
    forms/src/form1.cpp \
    forms/src/form2.cpp \
    forms/src/form3.cpp \
    forms/src/form4.cpp \
    forms/src/form5.cpp \
    forms/src/form6.cpp \
    forms/src/form7.cpp \
    forms/src/form8.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    forms/include/helloform.h \
    forms/include/conclusion.h \
    forms/include/form1.h \
    forms/include/form2.h \
    forms/include/form3.h \
    forms/include/form4.h \
    forms/include/form5.h \
    forms/include/form6.h \
    forms/include/form7.h \
    forms/include/form8.h \
    include/mainwindow.h

FORMS += \
    forms/ui/helloform.ui \
    forms/ui/conclusion.ui \
    forms/ui/form1.ui \
    forms/ui/form2.ui \
    forms/ui/form3.ui \
    forms/ui/form4.ui \
    forms/ui/form5.ui \
    forms/ui/form6.ui \
    forms/ui/form7.ui \
    forms/ui/form8.ui \
    ui/mainwindow.ui

INCLUDEPATH += \ 
    $$PWD/include \
    $$PWD/forms/include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc

DISTFILES +=
