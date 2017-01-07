TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += "-L/usr/lib64" -lboost_program_options
LIBS += "-L/lib64" -lglut
LIBS += "-L/lib64" -lGL \
                   -lGLU

SOURCES += main.cpp \
    FileIO.cpp \
    List.cpp \
    Vector3f.cpp \
    VisualisationMain.cpp \
    Visualiser.cpp

HEADERS += \
    FileIO.h \
    List.h \
    Vector3f.h \
    VisualisationMain.h \
    Visualiser.h \
    global.h
