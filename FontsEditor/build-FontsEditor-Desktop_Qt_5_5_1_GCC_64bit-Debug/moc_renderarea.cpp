/****************************************************************************
** Meta object code from reading C++ file 'renderarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FontsEditor/renderarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RenderArea_t {
    QByteArrayData data[27];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderArea_t qt_meta_stringdata_RenderArea = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RenderArea"
QT_MOC_LITERAL(1, 11, 18), // "activeIndexChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "setPenWidth"
QT_MOC_LITERAL(4, 43, 5), // "width"
QT_MOC_LITERAL(5, 49, 8), // "setBrush"
QT_MOC_LITERAL(6, 58, 2), // "br"
QT_MOC_LITERAL(7, 61, 9), // "swapBrush"
QT_MOC_LITERAL(8, 71, 19), // "addNewActiveContour"
QT_MOC_LITERAL(9, 91, 7), // "Contour"
QT_MOC_LITERAL(10, 99, 1), // "c"
QT_MOC_LITERAL(11, 101, 19), // "changeActiveContour"
QT_MOC_LITERAL(12, 121, 1), // "i"
QT_MOC_LITERAL(13, 123, 23), // "deleteLastPointIfExists"
QT_MOC_LITERAL(14, 147, 19), // "deleteActiveContour"
QT_MOC_LITERAL(15, 167, 17), // "copyActiveContour"
QT_MOC_LITERAL(16, 185, 17), // "moveActiveContour"
QT_MOC_LITERAL(17, 203, 2), // "dx"
QT_MOC_LITERAL(18, 206, 2), // "dy"
QT_MOC_LITERAL(19, 209, 11), // "selectPoint"
QT_MOC_LITERAL(20, 221, 19), // "changeSelectedPoint"
QT_MOC_LITERAL(21, 241, 20), // "selectPointAsDefault"
QT_MOC_LITERAL(22, 262, 11), // "setContours"
QT_MOC_LITERAL(23, 274, 20), // "std::vector<Contour>"
QT_MOC_LITERAL(24, 295, 5), // "conts"
QT_MOC_LITERAL(25, 301, 8), // "getBrush"
QT_MOC_LITERAL(26, 310, 21) // "getActiveContourIndex"

    },
    "RenderArea\0activeIndexChanged\0\0"
    "setPenWidth\0width\0setBrush\0br\0swapBrush\0"
    "addNewActiveContour\0Contour\0c\0"
    "changeActiveContour\0i\0deleteLastPointIfExists\0"
    "deleteActiveContour\0copyActiveContour\0"
    "moveActiveContour\0dx\0dy\0selectPoint\0"
    "changeSelectedPoint\0selectPointAsDefault\0"
    "setContours\0std::vector<Contour>\0conts\0"
    "getBrush\0getActiveContourIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   97,    2, 0x0a /* Public */,
       5,    1,  100,    2, 0x0a /* Public */,
       7,    0,  103,    2, 0x0a /* Public */,
       8,    1,  104,    2, 0x0a /* Public */,
      11,    1,  107,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    0,  112,    2, 0x0a /* Public */,
      16,    2,  113,    2, 0x0a /* Public */,
      19,    1,  118,    2, 0x0a /* Public */,
      20,    1,  121,    2, 0x0a /* Public */,
      21,    0,  124,    2, 0x0a /* Public */,
      22,    1,  125,    2, 0x0a /* Public */,
      25,    0,  128,    2, 0x0a /* Public */,
      26,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QBrush,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QPoint,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::QBrush,
    QMetaType::Int,

       0        // eod
};

void RenderArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderArea *_t = static_cast<RenderArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setBrush((*reinterpret_cast< QBrush(*)>(_a[1]))); break;
        case 3: _t->swapBrush(); break;
        case 4: _t->addNewActiveContour((*reinterpret_cast< Contour(*)>(_a[1]))); break;
        case 5: _t->changeActiveContour((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->deleteLastPointIfExists(); break;
        case 7: _t->deleteActiveContour(); break;
        case 8: _t->copyActiveContour(); break;
        case 9: _t->moveActiveContour((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->selectPoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->changeSelectedPoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->selectPointAsDefault(); break;
        case 13: _t->setContours((*reinterpret_cast< std::vector<Contour>(*)>(_a[1]))); break;
        case 14: { QBrush _r = _t->getBrush();
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->getActiveContourIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RenderArea::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderArea::activeIndexChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RenderArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RenderArea.data,
      qt_meta_data_RenderArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RenderArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RenderArea.stringdata0))
        return static_cast<void*>(const_cast< RenderArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int RenderArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void RenderArea::activeIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
