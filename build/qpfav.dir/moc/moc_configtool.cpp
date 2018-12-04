/****************************************************************************
** Meta object code from reading C++ file 'configtool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qpfav/configtool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configtool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QPF__ModelView_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPF__ModelView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPF__ModelView_t qt_meta_stringdata_QPF__ModelView = {
    {
QT_MOC_LITERAL(0, 0, 14) // "QPF::ModelView"

    },
    "QPF::ModelView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPF__ModelView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QPF::ModelView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QPF::ModelView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPF__ModelView.data,
      qt_meta_data_QPF__ModelView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QPF::ModelView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPF::ModelView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QPF__ModelView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QPF::ModelView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QPF__ConfigTool_t {
    QByteArrayData data[42];
    char stringdata0[469];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPF__ConfigTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPF__ConfigTool_t qt_meta_stringdata_QPF__ConfigTool = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QPF::ConfigTool"
QT_MOC_LITERAL(1, 16, 4), // "save"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "saveAs"
QT_MOC_LITERAL(4, 29, 5), // "apply"
QT_MOC_LITERAL(5, 35, 14), // "closeDoNothing"
QT_MOC_LITERAL(6, 50, 14), // "selectBasePath"
QT_MOC_LITERAL(7, 65, 15), // "setWorkingPaths"
QT_MOC_LITERAL(8, 81, 7), // "newPath"
QT_MOC_LITERAL(9, 89, 21), // "selectUserDefAreaPath"
QT_MOC_LITERAL(10, 111, 12), // "defineUserWA"
QT_MOC_LITERAL(11, 124, 3), // "btn"
QT_MOC_LITERAL(12, 128, 16), // "selectIPythonCmd"
QT_MOC_LITERAL(13, 145, 23), // "selectIPythonWorkingDir"
QT_MOC_LITERAL(14, 169, 7), // "addHost"
QT_MOC_LITERAL(15, 177, 10), // "removeHost"
QT_MOC_LITERAL(16, 188, 8), // "editHost"
QT_MOC_LITERAL(17, 197, 3), // "idx"
QT_MOC_LITERAL(18, 201, 8), // "addSwarm"
QT_MOC_LITERAL(19, 210, 11), // "removeSwarm"
QT_MOC_LITERAL(20, 222, 9), // "editSwarm"
QT_MOC_LITERAL(21, 232, 10), // "addProduct"
QT_MOC_LITERAL(22, 243, 13), // "removeProduct"
QT_MOC_LITERAL(23, 257, 12), // "addProcessor"
QT_MOC_LITERAL(24, 270, 15), // "removeProcessor"
QT_MOC_LITERAL(25, 286, 7), // "addRule"
QT_MOC_LITERAL(26, 294, 10), // "removeRule"
QT_MOC_LITERAL(27, 305, 8), // "editRule"
QT_MOC_LITERAL(28, 314, 15), // "removeFromTable"
QT_MOC_LITERAL(29, 330, 18), // "QAbstractItemView*"
QT_MOC_LITERAL(30, 349, 2), // "vw"
QT_MOC_LITERAL(31, 352, 4), // "item"
QT_MOC_LITERAL(32, 357, 10), // "addNewTool"
QT_MOC_LITERAL(33, 368, 8), // "editTool"
QT_MOC_LITERAL(34, 377, 3), // "row"
QT_MOC_LITERAL(35, 381, 10), // "removeTool"
QT_MOC_LITERAL(36, 392, 9), // "cancelDlg"
QT_MOC_LITERAL(37, 402, 18), // "changeToolWithItem"
QT_MOC_LITERAL(38, 421, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(39, 439, 14), // "saveAsFilename"
QT_MOC_LITERAL(40, 454, 8), // "QString&"
QT_MOC_LITERAL(41, 463, 5) // "fName"

    },
    "QPF::ConfigTool\0save\0\0saveAs\0apply\0"
    "closeDoNothing\0selectBasePath\0"
    "setWorkingPaths\0newPath\0selectUserDefAreaPath\0"
    "defineUserWA\0btn\0selectIPythonCmd\0"
    "selectIPythonWorkingDir\0addHost\0"
    "removeHost\0editHost\0idx\0addSwarm\0"
    "removeSwarm\0editSwarm\0addProduct\0"
    "removeProduct\0addProcessor\0removeProcessor\0"
    "addRule\0removeRule\0editRule\0removeFromTable\0"
    "QAbstractItemView*\0vw\0item\0addNewTool\0"
    "editTool\0row\0removeTool\0cancelDlg\0"
    "changeToolWithItem\0QTableWidgetItem*\0"
    "saveAsFilename\0QString&\0fName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPF__ConfigTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x0a /* Public */,
       3,    0,  175,    2, 0x0a /* Public */,
       4,    0,  176,    2, 0x0a /* Public */,
       5,    0,  177,    2, 0x0a /* Public */,
       6,    0,  178,    2, 0x0a /* Public */,
       7,    1,  179,    2, 0x0a /* Public */,
       9,    0,  182,    2, 0x0a /* Public */,
      10,    1,  183,    2, 0x0a /* Public */,
      12,    0,  186,    2, 0x0a /* Public */,
      13,    0,  187,    2, 0x0a /* Public */,
      14,    0,  188,    2, 0x08 /* Private */,
      15,    0,  189,    2, 0x08 /* Private */,
      16,    1,  190,    2, 0x08 /* Private */,
      18,    0,  193,    2, 0x08 /* Private */,
      19,    0,  194,    2, 0x08 /* Private */,
      20,    1,  195,    2, 0x08 /* Private */,
      21,    0,  198,    2, 0x08 /* Private */,
      22,    0,  199,    2, 0x08 /* Private */,
      23,    0,  200,    2, 0x08 /* Private */,
      24,    0,  201,    2, 0x08 /* Private */,
      25,    0,  202,    2, 0x08 /* Private */,
      26,    0,  203,    2, 0x08 /* Private */,
      27,    1,  204,    2, 0x08 /* Private */,
      28,    2,  207,    2, 0x08 /* Private */,
      32,    0,  212,    2, 0x08 /* Private */,
      33,    1,  213,    2, 0x08 /* Private */,
      33,    0,  216,    2, 0x08 /* Private */,
      33,    1,  217,    2, 0x08 /* Private */,
      35,    0,  220,    2, 0x08 /* Private */,
      36,    0,  221,    2, 0x08 /* Private */,
      37,    1,  222,    2, 0x08 /* Private */,
      39,    1,  225,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void, 0x80000000 | 29, QMetaType::QString,   30,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38,   31,
    QMetaType::Void, 0x80000000 | 40,   41,

       0        // eod
};

void QPF::ConfigTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigTool *_t = static_cast<ConfigTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->saveAs(); break;
        case 2: _t->apply(); break;
        case 3: _t->closeDoNothing(); break;
        case 4: _t->selectBasePath(); break;
        case 5: _t->setWorkingPaths((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->selectUserDefAreaPath(); break;
        case 7: _t->defineUserWA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->selectIPythonCmd(); break;
        case 9: _t->selectIPythonWorkingDir(); break;
        case 10: _t->addHost(); break;
        case 11: _t->removeHost(); break;
        case 12: _t->editHost((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 13: _t->addSwarm(); break;
        case 14: _t->removeSwarm(); break;
        case 15: _t->editSwarm((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 16: _t->addProduct(); break;
        case 17: _t->removeProduct(); break;
        case 18: _t->addProcessor(); break;
        case 19: _t->removeProcessor(); break;
        case 20: _t->addRule(); break;
        case 21: _t->removeRule(); break;
        case 22: _t->editRule((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 23: _t->removeFromTable((*reinterpret_cast< QAbstractItemView*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 24: _t->addNewTool(); break;
        case 25: _t->editTool((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 26: _t->editTool(); break;
        case 27: _t->editTool((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->removeTool(); break;
        case 29: _t->cancelDlg(); break;
        case 30: _t->changeToolWithItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 31: _t->saveAsFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemView* >(); break;
            }
            break;
        }
    }
}

const QMetaObject QPF::ConfigTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QPF__ConfigTool.data,
      qt_meta_data_QPF__ConfigTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QPF::ConfigTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPF::ConfigTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QPF__ConfigTool.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QPF::ConfigTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
