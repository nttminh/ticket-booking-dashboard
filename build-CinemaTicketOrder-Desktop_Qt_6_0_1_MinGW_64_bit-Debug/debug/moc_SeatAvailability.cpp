/****************************************************************************
** Meta object code from reading C++ file 'SeatAvailability.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CinemaTicketOrder/SeatAvailability.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SeatAvailability.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SeatAvailability_t {
    const uint offsetsAndSize[28];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SeatAvailability_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SeatAvailability_t qt_meta_stringdata_SeatAvailability = {
    {
QT_MOC_LITERAL(0, 16), // "SeatAvailability"
QT_MOC_LITERAL(17, 10), // "chooseSeat"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(51, 19), // "updateSeatAvailable"
QT_MOC_LITERAL(71, 10), // "movieIndex"
QT_MOC_LITERAL(82, 8), // "timeSlot"
QT_MOC_LITERAL(91, 18), // "updateDisableSeats"
QT_MOC_LITERAL(110, 12), // "QList<bool>&"
QT_MOC_LITERAL(123, 6), // "vector"
QT_MOC_LITERAL(130, 12), // "toVectorBool"
QT_MOC_LITERAL(143, 11), // "QList<bool>"
QT_MOC_LITERAL(155, 6), // "buffer"
QT_MOC_LITERAL(162, 26) // "connectAllButtonToFunction"

    },
    "SeatAvailability\0chooseSeat\0\0"
    "on_pushButton_clicked\0updateSeatAvailable\0"
    "movieIndex\0timeSlot\0updateDisableSeats\0"
    "QList<bool>&\0vector\0toVectorBool\0"
    "QList<bool>\0buffer\0connectAllButtonToFunction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeatAvailability[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    0,   51,    2, 0x08,    1 /* Private */,
       4,    2,   52,    2, 0x08,    2 /* Private */,
       7,    1,   57,    2, 0x08,    5 /* Private */,
      10,    1,   60,    2, 0x08,    7 /* Private */,
      13,    0,   63,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    0x80000000 | 11, QMetaType::QByteArray,   12,
    QMetaType::Void,

       0        // eod
};

void SeatAvailability::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SeatAvailability *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->chooseSeat(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->updateSeatAvailable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->updateDisableSeats((*reinterpret_cast< QList<bool>(*)>(_a[1]))); break;
        case 4: { QList<bool> _r = _t->toVectorBool((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<bool>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->connectAllButtonToFunction(); break;
        default: ;
        }
    }
}

const QMetaObject SeatAvailability::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SeatAvailability.offsetsAndSize,
    qt_meta_data_SeatAvailability,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SeatAvailability_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<bool> &, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SeatAvailability::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeatAvailability::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeatAvailability.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SeatAvailability::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
