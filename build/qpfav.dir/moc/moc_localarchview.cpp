/****************************************************************************
** Meta object code from reading C++ file 'localarchview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qpfav/localarchview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localarchview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalArchiveView_t {
    QByteArrayData data[10];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalArchiveView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalArchiveView_t qt_meta_stringdata_LocalArchiveView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LocalArchiveView"
QT_MOC_LITERAL(1, 17, 15), // "autoBtnsChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "topLeft"
QT_MOC_LITERAL(4, 42, 11), // "bottomRight"
QT_MOC_LITERAL(5, 54, 3), // "run"
QT_MOC_LITERAL(6, 58, 8), // "arefresh"
QT_MOC_LITERAL(7, 67, 7), // "aexpand"
QT_MOC_LITERAL(8, 75, 9), // "acollapse"
QT_MOC_LITERAL(9, 85, 7) // "aresize"

    },
    "LocalArchiveView\0autoBtnsChanged\0\0"
    "topLeft\0bottomRight\0run\0arefresh\0"
    "aexpand\0acollapse\0aresize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalArchiveView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LocalArchiveView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LocalArchiveView *_t = static_cast<LocalArchiveView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->autoBtnsChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->run(); break;
        case 2: _t->arefresh(); break;
        case 3: _t->aexpand(); break;
        case 4: _t->acollapse(); break;
        case 5: _t->aresize(); break;
        default: ;
        }
    }
}

const QMetaObject LocalArchiveView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LocalArchiveView.data,
      qt_meta_data_LocalArchiveView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LocalArchiveView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalArchiveView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalArchiveView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LocalArchiveView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
