/****************************************************************************
** Meta object code from reading C++ file 'geometryshape.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Figures/geometryshape.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geometryshape.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGeometryShapeENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGeometryShapeENDCLASS = QtMocHelpers::stringData(
    "GeometryShape",
    "on_SetRotation_clicked",
    "",
    "on_ConfirmRotationSettings_clicked",
    "on_SetScale_clicked",
    "on_ConfirmScaleSettings_clicked",
    "on_EnableMoving_Clicked",
    "on_showMassCenterChange_clicked",
    "on_confirmMassCenterChange_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGeometryShapeENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[35];
    char stringdata4[20];
    char stringdata5[32];
    char stringdata6[24];
    char stringdata7[32];
    char stringdata8[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGeometryShapeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGeometryShapeENDCLASS_t qt_meta_stringdata_CLASSGeometryShapeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "GeometryShape"
        QT_MOC_LITERAL(14, 22),  // "on_SetRotation_clicked"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 34),  // "on_ConfirmRotationSettings_cl..."
        QT_MOC_LITERAL(73, 19),  // "on_SetScale_clicked"
        QT_MOC_LITERAL(93, 31),  // "on_ConfirmScaleSettings_clicked"
        QT_MOC_LITERAL(125, 23),  // "on_EnableMoving_Clicked"
        QT_MOC_LITERAL(149, 31),  // "on_showMassCenterChange_clicked"
        QT_MOC_LITERAL(181, 34)   // "on_confirmMassCenterChange_cl..."
    },
    "GeometryShape",
    "on_SetRotation_clicked",
    "",
    "on_ConfirmRotationSettings_clicked",
    "on_SetScale_clicked",
    "on_ConfirmScaleSettings_clicked",
    "on_EnableMoving_Clicked",
    "on_showMassCenterChange_clicked",
    "on_confirmMassCenterChange_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGeometryShapeENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GeometryShape::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGeometryShapeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGeometryShapeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGeometryShapeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GeometryShape, std::true_type>,
        // method 'on_SetRotation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ConfirmRotationSettings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SetScale_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ConfirmScaleSettings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EnableMoving_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showMassCenterChange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_confirmMassCenterChange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GeometryShape::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeometryShape *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_SetRotation_clicked(); break;
        case 1: _t->on_ConfirmRotationSettings_clicked(); break;
        case 2: _t->on_SetScale_clicked(); break;
        case 3: _t->on_ConfirmScaleSettings_clicked(); break;
        case 4: _t->on_EnableMoving_Clicked(); break;
        case 5: _t->on_showMassCenterChange_clicked(); break;
        case 6: _t->on_confirmMassCenterChange_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *GeometryShape::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeometryShape::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGeometryShapeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GeometryShape::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
