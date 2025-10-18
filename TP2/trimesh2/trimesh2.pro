DESTDIR = ../trimesh2/lib

win32 {
    TEMPLATE = vclib
}
else {
    TEMPLATE = lib

    macx {
        DEFINES += DARWIN
        QMAKE_CXXFLAGS_WARN_OFF = -Wno-unknown-pragmas
    }
    else {
        DEFINES += LINUX
    }
}

CONFIG += staticlib
QT += opengl xml

TARGET = trimesh

DEPENDPATH += include
INCLUDEPATH += include

#Input
HEADERS += include/Box.h \
include/Color.h \
include/GLCamera.h \
include/ICP.h \
include/KDtree.h \
include/TriMesh.h \
include/TriMesh_algo.h \
include/Vec.h \
include/XForm.h \
include/bsphere.h \
include/lineqn.h \
include/mempool.h \
include/noise3d.h \
include/strutil.h \
include/timestamp.h

SOURCES += libsrc/GLCamera.cc \
libsrc/ICP.cc \
libsrc/KDtree.cc \
libsrc/TriMesh_bounding.cc \
libsrc/TriMesh_connectivity.cc \
libsrc/TriMesh_curvature.cc \
libsrc/TriMesh_grid.cc \
libsrc/TriMesh_io.cc \
libsrc/TriMesh_normals.cc \
libsrc/TriMesh_pointareas.cc \
libsrc/TriMesh_stats.cc \
libsrc/TriMesh_tstrips.cc \
libsrc/conn_comps.cc \
libsrc/diffuse.cc \
libsrc/edgeflip.cc \
libsrc/faceflip.cc \
libsrc/filter.cc \
libsrc/lmsmooth.cc \
libsrc/overlap.cc \
libsrc/remove.cc \
libsrc/reorder_verts.cc \
libsrc/shared.cc \
libsrc/subdiv.cc

