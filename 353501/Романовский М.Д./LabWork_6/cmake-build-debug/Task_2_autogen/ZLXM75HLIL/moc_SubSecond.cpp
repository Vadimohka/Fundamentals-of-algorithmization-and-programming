/****************************************************************************
** Meta object code from reading C++ file 'SubSecond.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Task_2/sub2/SubSecond.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SubSecond.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSubSecondENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSubSecondENDCLASS = QtMocHelpers::stringData(
    "SubSecond",
    "onSave",
    "",
    "onOpen",
    "onNewCount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSubSecondENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[10];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSubSecondENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSubSecondENDCLASS_t qt_meta_stringdata_CLASSSubSecondENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "SubSecond"
        QT_MOC_LITERAL(10, 6),  // "onSave"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 6),  // "onOpen"
        QT_MOC_LITERAL(25, 10)   // "onNewCount"
    },
    "SubSecond",
    "onSave",
    "",
    "onOpen",
    "onNewCount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSubSecondENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SubSecond::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSubSecondENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSubSecondENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSubSecondENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SubSecond, std::true_type>,
        // method 'onSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNewCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SubSecond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SubSecond *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSave(); break;
        case 1: _t->onOpen(); break;
        case 2: _t->onNewCount(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *SubSecond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubSecond::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSubSecondENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SubSecond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
