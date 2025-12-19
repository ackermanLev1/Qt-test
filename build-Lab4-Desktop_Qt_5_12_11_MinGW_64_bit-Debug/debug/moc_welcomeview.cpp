/****************************************************************************
** Meta object code from reading C++ file 'welcomeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab4/welcomeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WelcomeView_t {
    QByteArrayData data[8];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WelcomeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WelcomeView_t qt_meta_stringdata_WelcomeView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WelcomeView"
QT_MOC_LITERAL(1, 12, 16), // "goDepartmentView"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "goDoctorView"
QT_MOC_LITERAL(4, 43, 13), // "goPatientView"
QT_MOC_LITERAL(5, 57, 23), // "on_btDepartment_clicked"
QT_MOC_LITERAL(6, 81, 19), // "on_btDoctor_clicked"
QT_MOC_LITERAL(7, 101, 20) // "on_btPatient_clicked"

    },
    "WelcomeView\0goDepartmentView\0\0"
    "goDoctorView\0goPatientView\0"
    "on_btDepartment_clicked\0on_btDoctor_clicked\0"
    "on_btPatient_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WelcomeView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WelcomeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WelcomeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goDepartmentView(); break;
        case 1: _t->goDoctorView(); break;
        case 2: _t->goPatientView(); break;
        case 3: _t->on_btDepartment_clicked(); break;
        case 4: _t->on_btDoctor_clicked(); break;
        case 5: _t->on_btPatient_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WelcomeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::goDepartmentView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WelcomeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::goDoctorView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WelcomeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::goPatientView)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject WelcomeView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WelcomeView.data,
    qt_meta_data_WelcomeView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WelcomeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WelcomeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomeView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WelcomeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WelcomeView::goDepartmentView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WelcomeView::goDoctorView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WelcomeView::goPatientView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
