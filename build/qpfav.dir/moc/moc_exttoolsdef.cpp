/****************************************************************************
** Meta object code from reading C++ file 'exttoolsdef.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qpfav/exttoolsdef.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exttoolsdef.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QPF__ExtToolsDef_t {
    QByteArrayData data[11];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPF__ExtToolsDef_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPF__ExtToolsDef_t qt_meta_stringdata_QPF__ExtToolsDef = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QPF::ExtToolsDef"
QT_MOC_LITERAL(1, 17, 10), // "addNewTool"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "editTool"
QT_MOC_LITERAL(4, 38, 3), // "idx"
QT_MOC_LITERAL(5, 42, 3), // "row"
QT_MOC_LITERAL(6, 46, 10), // "removeTool"
QT_MOC_LITERAL(7, 57, 9), // "cancelDlg"
QT_MOC_LITERAL(8, 67, 18), // "changeToolWithItem"
QT_MOC_LITERAL(9, 86, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(10, 104, 4) // "item"

    },
    "QPF::ExtToolsDef\0addNewTool\0\0editTool\0"
    "idx\0row\0removeTool\0cancelDlg\0"
    "changeToolWithItem\0QTableWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPF__ExtToolsDef[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       3,    0,   53,    2, 0x08 /* Private */,
       3,    1,   54,    2, 0x08 /* Private */,
       6,    0,   57,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void QPF::ExtToolsDef::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExtToolsDef *_t = static_cast<ExtToolsDef *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addNewTool(); break;
        case 1: _t->editTool((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->editTool(); break;
        case 3: _t->editTool((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->removeTool(); break;
        case 5: _t->cancelDlg(); break;
        case 6: _t->changeToolWithItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QPF::ExtToolsDef::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QPF__ExtToolsDef.data,
      qt_meta_data_QPF__ExtToolsDef,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QPF::ExtToolsDef::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPF::ExtToolsDef::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QPF__ExtToolsDef.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QPF::ExtToolsDef::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
