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
    QByteArrayData data[20];
    char stringdata0[204];
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
QT_MOC_LITERAL(3, 31, 11), // "setFillRule"
QT_MOC_LITERAL(4, 43, 12), // "Qt::FillRule"
QT_MOC_LITERAL(5, 56, 4), // "rule"
QT_MOC_LITERAL(6, 61, 11), // "setPenWidth"
QT_MOC_LITERAL(7, 73, 5), // "width"
QT_MOC_LITERAL(8, 79, 11), // "setPenColor"
QT_MOC_LITERAL(9, 91, 5), // "color"
QT_MOC_LITERAL(10, 97, 8), // "setBrush"
QT_MOC_LITERAL(11, 106, 2), // "br"
QT_MOC_LITERAL(12, 109, 9), // "swapBrush"
QT_MOC_LITERAL(13, 119, 19), // "addNewActiveContour"
QT_MOC_LITERAL(14, 139, 7), // "Contour"
QT_MOC_LITERAL(15, 147, 1), // "c"
QT_MOC_LITERAL(16, 149, 19), // "changeActiveContour"
QT_MOC_LITERAL(17, 169, 1), // "i"
QT_MOC_LITERAL(18, 171, 23), // "deleteLastPointIfExists"
QT_MOC_LITERAL(19, 195, 8) // "getBrush"

    },
    "RenderArea\0activeIndexChanged\0\0"
    "setFillRule\0Qt::FillRule\0rule\0setPenWidth\0"
    "width\0setPenColor\0color\0setBrush\0br\0"
    "swapBrush\0addNewActiveContour\0Contour\0"
    "c\0changeActiveContour\0i\0deleteLastPointIfExists\0"
    "getBrush"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   67,    2, 0x0a /* Public */,
       6,    1,   70,    2, 0x0a /* Public */,
       8,    1,   73,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      16,    1,   83,    2, 0x0a /* Public */,
      18,    0,   86,    2, 0x0a /* Public */,
      19,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::QBrush,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::QBrush,

       0        // eod
};

void RenderArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderArea *_t = static_cast<RenderArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setFillRule((*reinterpret_cast< Qt::FillRule(*)>(_a[1]))); break;
        case 2: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setPenColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setBrush((*reinterpret_cast< QBrush(*)>(_a[1]))); break;
        case 5: _t->swapBrush(); break;
        case 6: _t->addNewActiveContour((*reinterpret_cast< Contour(*)>(_a[1]))); break;
        case 7: _t->changeActiveContour((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->deleteLastPointIfExists(); break;
        case 9: { QBrush _r = _t->getBrush();
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = _r; }  break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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
