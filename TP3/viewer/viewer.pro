# if (mac OS X)
DESTDIR = ../viewer
# ENDIF
QT       += core gui opengl 
CONFIG += console

TARGET = myViewer
TEMPLATE = app

macx {
  QMAKE_CXXFLAGS += -Wno-unknown-pragmas
} else {
  QMAKE_LFLAGS += -Wno-unknown-pragmas -fopenmp 
}

SOURCES +=  \
            src/main.cpp \
            src/openglwindow.cpp \
            src/glshaderwindow.cpp \
            src/bvh/bvh.cpp

HEADERS  += \
            src/openglwindow.h \
            src/glshaderwindow.h \
    src/perlinNoise.h \
    src/bvh/bvh.hpp \
    src/bvh/bbox.hpp \
    src/bvh/triangle.hpp \
    src/bvh/vector.hpp

# trimesh library for loading objects.
# Reference/source: http://gfx.cs.princeton.edu/proj/trimesh2/
INCLUDEPATH += ../trimesh2/include/ src/

LIBS += -L../trimesh2/lib -ltrimesh


