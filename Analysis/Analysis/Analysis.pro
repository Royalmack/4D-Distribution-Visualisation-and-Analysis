TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += "-L/usr/lib64" -lboost_program_options
LIBS += -L/lib -lgsl -lgslcblas -lm

SOURCES += main.cpp \
    FileIO.cpp \
    Analysis.cpp \
    List.cpp \
    Vector3f.cpp \
    packing.cpp \
    Quaternion.cpp \
    AnalysisMain.cpp

HEADERS += \
    FileIO.h \
    Analysis.h \
    List.h \
    Vector3f.h \
    packing.h \
    Quaternion.h \
    AnalysisMain.h
