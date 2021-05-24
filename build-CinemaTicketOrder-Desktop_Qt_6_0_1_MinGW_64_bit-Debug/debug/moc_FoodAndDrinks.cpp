/****************************************************************************
** Meta object code from reading C++ file 'FoodAndDrinks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CinemaTicketOrder/FoodAndDrinks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FoodAndDrinks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FoodAndDrinks_t {
    const uint offsetsAndSize[32];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FoodAndDrinks_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FoodAndDrinks_t qt_meta_stringdata_FoodAndDrinks = {
    {
QT_MOC_LITERAL(0, 13), // "FoodAndDrinks"
QT_MOC_LITERAL(14, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 10), // "chooseItem"
QT_MOC_LITERAL(48, 4), // "item"
QT_MOC_LITERAL(53, 11), // "indexToName"
QT_MOC_LITERAL(65, 5), // "index"
QT_MOC_LITERAL(71, 12), // "indexToPrice"
QT_MOC_LITERAL(84, 22), // "connectAllButtonToSlot"
QT_MOC_LITERAL(107, 8), // "clearAll"
QT_MOC_LITERAL(116, 8), // "checkOut"
QT_MOC_LITERAL(125, 11), // "toByteArray"
QT_MOC_LITERAL(137, 11), // "QList<bool>"
QT_MOC_LITERAL(149, 4), // "data"
QT_MOC_LITERAL(154, 30), // "on_pushButton_clearAll_clicked"
QT_MOC_LITERAL(185, 30) // "on_pushButton_checkOut_clicked"

    },
    "FoodAndDrinks\0on_pushButton_clicked\0"
    "\0chooseItem\0item\0indexToName\0index\0"
    "indexToPrice\0connectAllButtonToSlot\0"
    "clearAll\0checkOut\0toByteArray\0QList<bool>\0"
    "data\0on_pushButton_clearAll_clicked\0"
    "on_pushButton_checkOut_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FoodAndDrinks[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    0 /* Private */,
       3,    1,   75,    2, 0x08,    1 /* Private */,
       5,    1,   78,    2, 0x08,    3 /* Private */,
       7,    1,   81,    2, 0x08,    5 /* Private */,
       8,    0,   84,    2, 0x08,    7 /* Private */,
       9,    0,   85,    2, 0x08,    8 /* Private */,
      10,    0,   86,    2, 0x08,    9 /* Private */,
      11,    1,   87,    2, 0x08,   10 /* Private */,
      14,    0,   90,    2, 0x08,   12 /* Private */,
      15,    0,   91,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::Double, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QByteArray, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FoodAndDrinks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FoodAndDrinks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->chooseItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QString _r = _t->indexToName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->indexToPrice((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->connectAllButtonToSlot(); break;
        case 5: _t->clearAll(); break;
        case 6: _t->checkOut(); break;
        case 7: { QByteArray _r = _t->toByteArray((*reinterpret_cast< const QList<bool>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_pushButton_clearAll_clicked(); break;
        case 9: _t->on_pushButton_checkOut_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<bool> >(); break;
            }
            break;
        }
    }
}

const QMetaObject FoodAndDrinks::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FoodAndDrinks.offsetsAndSize,
    qt_meta_data_FoodAndDrinks,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FoodAndDrinks_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<bool> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FoodAndDrinks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FoodAndDrinks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FoodAndDrinks.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FoodAndDrinks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
