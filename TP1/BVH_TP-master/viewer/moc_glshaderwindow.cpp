/****************************************************************************
** Meta object code from reading C++ file 'glshaderwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/glshaderwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glshaderwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_glShaderWindow_t {
    QByteArrayData data[22];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_glShaderWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_glShaderWindow_t qt_meta_stringdata_glShaderWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "glShaderWindow"
QT_MOC_LITERAL(1, 15, 17), // "openSceneFromFile"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "openNewTexture"
QT_MOC_LITERAL(4, 49, 13), // "openNewEnvMap"
QT_MOC_LITERAL(5, 63, 9), // "saveScene"
QT_MOC_LITERAL(6, 73, 16), // "toggleFullScreen"
QT_MOC_LITERAL(7, 90, 14), // "saveScreenshot"
QT_MOC_LITERAL(8, 105, 13), // "makeAuxWindow"
QT_MOC_LITERAL(9, 119, 8), // "QWidget*"
QT_MOC_LITERAL(10, 128, 13), // "setWindowSize"
QT_MOC_LITERAL(11, 142, 4), // "size"
QT_MOC_LITERAL(12, 147, 19), // "cookTorranceClicked"
QT_MOC_LITERAL(13, 167, 17), // "blinnPhongClicked"
QT_MOC_LITERAL(14, 185, 18), // "transparentClicked"
QT_MOC_LITERAL(15, 204, 13), // "opaqueClicked"
QT_MOC_LITERAL(16, 218, 20), // "updateLightIntensity"
QT_MOC_LITERAL(17, 239, 16), // "lightSliderValue"
QT_MOC_LITERAL(18, 256, 15), // "updateShininess"
QT_MOC_LITERAL(19, 272, 20), // "shininessSliderValue"
QT_MOC_LITERAL(20, 293, 9), // "updateEta"
QT_MOC_LITERAL(21, 303, 14) // "etaSliderValue"

    },
    "glShaderWindow\0openSceneFromFile\0\0"
    "openNewTexture\0openNewEnvMap\0saveScene\0"
    "toggleFullScreen\0saveScreenshot\0"
    "makeAuxWindow\0QWidget*\0setWindowSize\0"
    "size\0cookTorranceClicked\0blinnPhongClicked\0"
    "transparentClicked\0opaqueClicked\0"
    "updateLightIntensity\0lightSliderValue\0"
    "updateShininess\0shininessSliderValue\0"
    "updateEta\0etaSliderValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_glShaderWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
      10,    1,   96,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    1,  103,    2, 0x0a /* Public */,
      18,    1,  106,    2, 0x0a /* Public */,
      20,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void glShaderWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<glShaderWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openSceneFromFile(); break;
        case 1: _t->openNewTexture(); break;
        case 2: _t->openNewEnvMap(); break;
        case 3: _t->saveScene(); break;
        case 4: _t->toggleFullScreen(); break;
        case 5: _t->saveScreenshot(); break;
        case 6: { QWidget* _r = _t->makeAuxWindow();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setWindowSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->cookTorranceClicked(); break;
        case 9: _t->blinnPhongClicked(); break;
        case 10: _t->transparentClicked(); break;
        case 11: _t->opaqueClicked(); break;
        case 12: _t->updateLightIntensity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateShininess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->updateEta((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject glShaderWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<OpenGLWindow::staticMetaObject>(),
    qt_meta_stringdata_glShaderWindow.data,
    qt_meta_data_glShaderWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *glShaderWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *glShaderWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_glShaderWindow.stringdata0))
        return static_cast<void*>(this);
    return OpenGLWindow::qt_metacast(_clname);
}

int glShaderWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OpenGLWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
