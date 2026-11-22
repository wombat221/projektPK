QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Generator.cpp \
    KonfiguracjaJSON.cpp \
    ModelARX.cpp \
    ProstyUAR.cpp \
    RegulatorPID.cpp \
    WartstwaUslugi.cpp \
    ZegarSymulacji.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Generator.h \
    KonfiguracjaJSON.h \
    ModelARX.h \
    ProstyUAR.h \
    RegulatorPID.h \
    WartstwaUslugi.h \
    ZegarSymulacji.h \
    json.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += console