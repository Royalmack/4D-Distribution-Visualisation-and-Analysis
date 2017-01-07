TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += "-L/usr/lib64" -lboost_program_options
LIBS += "-L/lib64" -lgtest

SOURCES += main.cpp \
    Fileio.cpp \
    Vector3f.cpp \
    GenManager.cpp \
    List.cpp \
    RandomDistribution.cpp \
    Boxmuller.cpp \
    Fishman.cpp \
    Quaternion.cpp \
    Generatormain.cpp \
    testharness.cpp

HEADERS += \
    stdfx.h \
    Fileio.h \
    Vector3f.h \
    GenManager.h \
    List.h \
    RandomDistribution.h \
    Boxmuller.h \
    Fishman.h \
    Quaternion.h \
    Generatormain.h
