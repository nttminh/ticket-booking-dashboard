/****************************************************************************
** Meta object code from reading C++ file 'ShowtimeAdmin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CinemaTicketOrder/ShowtimeAdmin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShowtimeAdmin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowtimeAdmin_t {
    const uint offsetsAndSize[12];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ShowtimeAdmin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ShowtimeAdmin_t qt_meta_stringdata_ShowtimeAdmin = {
    {
QT_MOC_LITERAL(0, 13), // "ShowtimeAdmin"
QT_MOC_LITERAL(14, 26), // "on_btn_choosePhoto_clicked"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 23), // "on_btn_addMovie_clicked"
QT_MOC_LITERAL(66, 26), // "on_btn_removeMovie_clicked"
QT_MOC_LITERAL(93, 28) // "on_pushButton_export_clicked"

    },
    "ShowtimeAdmin\0on_btn_choosePhoto_clicked\0"
    "\0on_btn_addMovie_clicked\0"
    "on_btn_removeMovie_clicked\0"
    "on_pushButton_export_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowtimeAdmin[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    0 /* Private */,
       3,    0,   39,    2, 0x08,    1 /* Private */,
       4,    0,   40,    2, 0x08,    2 /* Private */,
       5,    0,   41,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShowtimeAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowtimeAdmin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_choosePhoto_clicked(); break;
        case 1: _t->on_btn_addMovie_clicked(); break;
        case 2: _t->on_btn_removeMovie_clicked(); break;
        case 3: _t->on_pushButton_export_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ShowtimeAdmin::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ShowtimeAdmin.offsetsAndSize,
    qt_meta_data_ShowtimeAdmin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ShowtimeAdmin_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ShowtimeAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowtimeAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowtimeAdmin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ShowtimeAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
