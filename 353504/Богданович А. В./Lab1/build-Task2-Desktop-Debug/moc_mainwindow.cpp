/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Task2/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButton_clicked",
    "",
    "on_pushButton_moveUp_clicked",
    "on_pushButton_moveRight_clicked",
    "on_pushButton_moveDown_clicked",
    "on_pushButton_moveLeft_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_8_clicked",
    "on_pushButton_9_clicked",
    "on_spinBox_valueChanged",
    "arg1",
    "on_spinBox_2_valueChanged",
    "on_pushButton_4_clicked",
    "on_pushButton_5_clicked",
    "on_pushButton_moveUp_pressed",
    "on_pushButton_moveUp_released",
    "moveUpSlot",
    "moveDownSlot",
    "moveRightSlot",
    "moveLeftSlot",
    "rotateRightSlot",
    "rotateLeftSlot",
    "upScaleSlot",
    "downScaleSlot",
    "on_pushButton_moveRight_pressed",
    "on_pushButton_moveRight_released",
    "on_pushButton_moveDown_pressed",
    "on_pushButton_moveDown_released",
    "on_pushButton_moveLeft_pressed",
    "on_pushButton_moveLeft_released",
    "on_pushButton_2_pressed",
    "on_pushButton_2_released",
    "on_pushButton_3_pressed",
    "on_pushButton_3_released",
    "on_pushButton_8_pressed",
    "on_pushButton_8_released",
    "on_pushButton_9_pressed",
    "on_pushButton_9_released",
    "on_pushButton_6_clicked",
    "on_checkBox_stateChanged",
    "on_radioButton_2_clicked",
    "on_radioButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[88];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[29];
    char stringdata4[32];
    char stringdata5[31];
    char stringdata6[31];
    char stringdata7[24];
    char stringdata8[24];
    char stringdata9[24];
    char stringdata10[24];
    char stringdata11[24];
    char stringdata12[5];
    char stringdata13[26];
    char stringdata14[24];
    char stringdata15[24];
    char stringdata16[29];
    char stringdata17[30];
    char stringdata18[11];
    char stringdata19[13];
    char stringdata20[14];
    char stringdata21[13];
    char stringdata22[16];
    char stringdata23[15];
    char stringdata24[12];
    char stringdata25[14];
    char stringdata26[32];
    char stringdata27[33];
    char stringdata28[31];
    char stringdata29[32];
    char stringdata30[31];
    char stringdata31[32];
    char stringdata32[24];
    char stringdata33[25];
    char stringdata34[24];
    char stringdata35[25];
    char stringdata36[24];
    char stringdata37[25];
    char stringdata38[24];
    char stringdata39[25];
    char stringdata40[24];
    char stringdata41[25];
    char stringdata42[25];
    char stringdata43[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 28),  // "on_pushButton_moveUp_clicked"
        QT_MOC_LITERAL(63, 31),  // "on_pushButton_moveRight_clicked"
        QT_MOC_LITERAL(95, 30),  // "on_pushButton_moveDown_clicked"
        QT_MOC_LITERAL(126, 30),  // "on_pushButton_moveLeft_clicked"
        QT_MOC_LITERAL(157, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(181, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(205, 23),  // "on_pushButton_8_clicked"
        QT_MOC_LITERAL(229, 23),  // "on_pushButton_9_clicked"
        QT_MOC_LITERAL(253, 23),  // "on_spinBox_valueChanged"
        QT_MOC_LITERAL(277, 4),  // "arg1"
        QT_MOC_LITERAL(282, 25),  // "on_spinBox_2_valueChanged"
        QT_MOC_LITERAL(308, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(332, 23),  // "on_pushButton_5_clicked"
        QT_MOC_LITERAL(356, 28),  // "on_pushButton_moveUp_pressed"
        QT_MOC_LITERAL(385, 29),  // "on_pushButton_moveUp_released"
        QT_MOC_LITERAL(415, 10),  // "moveUpSlot"
        QT_MOC_LITERAL(426, 12),  // "moveDownSlot"
        QT_MOC_LITERAL(439, 13),  // "moveRightSlot"
        QT_MOC_LITERAL(453, 12),  // "moveLeftSlot"
        QT_MOC_LITERAL(466, 15),  // "rotateRightSlot"
        QT_MOC_LITERAL(482, 14),  // "rotateLeftSlot"
        QT_MOC_LITERAL(497, 11),  // "upScaleSlot"
        QT_MOC_LITERAL(509, 13),  // "downScaleSlot"
        QT_MOC_LITERAL(523, 31),  // "on_pushButton_moveRight_pressed"
        QT_MOC_LITERAL(555, 32),  // "on_pushButton_moveRight_released"
        QT_MOC_LITERAL(588, 30),  // "on_pushButton_moveDown_pressed"
        QT_MOC_LITERAL(619, 31),  // "on_pushButton_moveDown_released"
        QT_MOC_LITERAL(651, 30),  // "on_pushButton_moveLeft_pressed"
        QT_MOC_LITERAL(682, 31),  // "on_pushButton_moveLeft_released"
        QT_MOC_LITERAL(714, 23),  // "on_pushButton_2_pressed"
        QT_MOC_LITERAL(738, 24),  // "on_pushButton_2_released"
        QT_MOC_LITERAL(763, 23),  // "on_pushButton_3_pressed"
        QT_MOC_LITERAL(787, 24),  // "on_pushButton_3_released"
        QT_MOC_LITERAL(812, 23),  // "on_pushButton_8_pressed"
        QT_MOC_LITERAL(836, 24),  // "on_pushButton_8_released"
        QT_MOC_LITERAL(861, 23),  // "on_pushButton_9_pressed"
        QT_MOC_LITERAL(885, 24),  // "on_pushButton_9_released"
        QT_MOC_LITERAL(910, 23),  // "on_pushButton_6_clicked"
        QT_MOC_LITERAL(934, 24),  // "on_checkBox_stateChanged"
        QT_MOC_LITERAL(959, 24),  // "on_radioButton_2_clicked"
        QT_MOC_LITERAL(984, 22)   // "on_radioButton_clicked"
    },
    "MainWindow",
    "on_pushButton_clicked",
    "",
    "on_pushButton_moveUp_clicked",
    "on_pushButton_moveRight_clicked",
    "on_pushButton_moveDown_clicked",
    "on_pushButton_moveLeft_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_8_clicked",
    "on_pushButton_9_clicked",
    "on_spinBox_valueChanged",
    "arg1",
    "on_spinBox_2_valueChanged",
    "on_pushButton_4_clicked",
    "on_pushButton_5_clicked",
    "on_pushButton_moveUp_pressed",
    "on_pushButton_moveUp_released",
    "moveUpSlot",
    "moveDownSlot",
    "moveRightSlot",
    "moveLeftSlot",
    "rotateRightSlot",
    "rotateLeftSlot",
    "upScaleSlot",
    "downScaleSlot",
    "on_pushButton_moveRight_pressed",
    "on_pushButton_moveRight_released",
    "on_pushButton_moveDown_pressed",
    "on_pushButton_moveDown_released",
    "on_pushButton_moveLeft_pressed",
    "on_pushButton_moveLeft_released",
    "on_pushButton_2_pressed",
    "on_pushButton_2_released",
    "on_pushButton_3_pressed",
    "on_pushButton_3_released",
    "on_pushButton_8_pressed",
    "on_pushButton_8_released",
    "on_pushButton_9_pressed",
    "on_pushButton_9_released",
    "on_pushButton_6_clicked",
    "on_checkBox_stateChanged",
    "on_radioButton_2_clicked",
    "on_radioButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  260,    2, 0x08,    1 /* Private */,
       3,    0,  261,    2, 0x08,    2 /* Private */,
       4,    0,  262,    2, 0x08,    3 /* Private */,
       5,    0,  263,    2, 0x08,    4 /* Private */,
       6,    0,  264,    2, 0x08,    5 /* Private */,
       7,    0,  265,    2, 0x08,    6 /* Private */,
       8,    0,  266,    2, 0x08,    7 /* Private */,
       9,    0,  267,    2, 0x08,    8 /* Private */,
      10,    0,  268,    2, 0x08,    9 /* Private */,
      11,    1,  269,    2, 0x08,   10 /* Private */,
      13,    1,  272,    2, 0x08,   12 /* Private */,
      14,    0,  275,    2, 0x08,   14 /* Private */,
      15,    0,  276,    2, 0x08,   15 /* Private */,
      16,    0,  277,    2, 0x08,   16 /* Private */,
      17,    0,  278,    2, 0x08,   17 /* Private */,
      18,    0,  279,    2, 0x08,   18 /* Private */,
      19,    0,  280,    2, 0x08,   19 /* Private */,
      20,    0,  281,    2, 0x08,   20 /* Private */,
      21,    0,  282,    2, 0x08,   21 /* Private */,
      22,    0,  283,    2, 0x08,   22 /* Private */,
      23,    0,  284,    2, 0x08,   23 /* Private */,
      24,    0,  285,    2, 0x08,   24 /* Private */,
      25,    0,  286,    2, 0x08,   25 /* Private */,
      26,    0,  287,    2, 0x08,   26 /* Private */,
      27,    0,  288,    2, 0x08,   27 /* Private */,
      28,    0,  289,    2, 0x08,   28 /* Private */,
      29,    0,  290,    2, 0x08,   29 /* Private */,
      30,    0,  291,    2, 0x08,   30 /* Private */,
      31,    0,  292,    2, 0x08,   31 /* Private */,
      32,    0,  293,    2, 0x08,   32 /* Private */,
      33,    0,  294,    2, 0x08,   33 /* Private */,
      34,    0,  295,    2, 0x08,   34 /* Private */,
      35,    0,  296,    2, 0x08,   35 /* Private */,
      36,    0,  297,    2, 0x08,   36 /* Private */,
      37,    0,  298,    2, 0x08,   37 /* Private */,
      38,    0,  299,    2, 0x08,   38 /* Private */,
      39,    0,  300,    2, 0x08,   39 /* Private */,
      40,    0,  301,    2, 0x08,   40 /* Private */,
      41,    1,  302,    2, 0x08,   41 /* Private */,
      42,    0,  305,    2, 0x08,   43 /* Private */,
      43,    0,  306,    2, 0x08,   44 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveUp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveRight_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveDown_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveLeft_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_8_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBox_2_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveUp_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveUp_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveUpSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveDownSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveRightSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveLeftSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotateRightSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotateLeftSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'upScaleSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'downScaleSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveRight_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveRight_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveDown_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveDown_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveLeft_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_moveLeft_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_8_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_8_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_radioButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_moveUp_clicked(); break;
        case 2: _t->on_pushButton_moveRight_clicked(); break;
        case 3: _t->on_pushButton_moveDown_clicked(); break;
        case 4: _t->on_pushButton_moveLeft_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_8_clicked(); break;
        case 8: _t->on_pushButton_9_clicked(); break;
        case 9: _t->on_spinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_spinBox_2_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_pushButton_5_clicked(); break;
        case 13: _t->on_pushButton_moveUp_pressed(); break;
        case 14: _t->on_pushButton_moveUp_released(); break;
        case 15: _t->moveUpSlot(); break;
        case 16: _t->moveDownSlot(); break;
        case 17: _t->moveRightSlot(); break;
        case 18: _t->moveLeftSlot(); break;
        case 19: _t->rotateRightSlot(); break;
        case 20: _t->rotateLeftSlot(); break;
        case 21: _t->upScaleSlot(); break;
        case 22: _t->downScaleSlot(); break;
        case 23: _t->on_pushButton_moveRight_pressed(); break;
        case 24: _t->on_pushButton_moveRight_released(); break;
        case 25: _t->on_pushButton_moveDown_pressed(); break;
        case 26: _t->on_pushButton_moveDown_released(); break;
        case 27: _t->on_pushButton_moveLeft_pressed(); break;
        case 28: _t->on_pushButton_moveLeft_released(); break;
        case 29: _t->on_pushButton_2_pressed(); break;
        case 30: _t->on_pushButton_2_released(); break;
        case 31: _t->on_pushButton_3_pressed(); break;
        case 32: _t->on_pushButton_3_released(); break;
        case 33: _t->on_pushButton_8_pressed(); break;
        case 34: _t->on_pushButton_8_released(); break;
        case 35: _t->on_pushButton_9_pressed(); break;
        case 36: _t->on_pushButton_9_released(); break;
        case 37: _t->on_pushButton_6_clicked(); break;
        case 38: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->on_radioButton_2_clicked(); break;
        case 40: _t->on_radioButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
