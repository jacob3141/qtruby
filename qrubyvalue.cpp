//
// Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
//
// This file is part of QtRuby.
//
// QtRuby is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// QtRuby is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with QtRuby.
// If not, see <http://www.gnu.org/licenses/>.
//
// It is possible to obtain a commercial license of QtRuby.
// Please contact Jacob Dawid <jacob@omg-it.works>
//

// Own includes
#include "qrubyvalue.h"
#include "qrubyid.h"

#include "qrubyobject.h"
#include "qrubyclass.h"

// Standard includes
#include <stdarg.h>

// Qt includes
#include <QVariant>
#include <QDebug>

class QRubyClass;
class QRubyModule;
class QRubyFloat;
class QRubyString;
class QRubyRegExp;
class QRubyArray;
class QRubyHash;
class QRubyStruct;
class QRubyBigNumber;
class QRubyFile;
class QRubyData;
class QRubyMatch;
class QRubyComplex;
class QRubyRational;
class QRubyNil;
class QRubyTrue;
class QRubyFalse;
class QRubySymbol;
class QRubyFixedNumber;
class QRubyUndefined;
class QRubyNode;
class QRubyIncludeClass;
class QRubyZombie;
class QRubyMask;

QRubyValue::QRubyValue(const QRubyValue& other) :
    _value(other._value) {
}

QRubyValue::QRubyValue(VALUE value) :
    _value(value) {
}

QRubyValue::QRubyValue(QVariant variant) {
    switch(variant.type()) {
    case QVariant::Invalid:
        break;
    case QVariant::Bool:
        break;
    case QVariant::Int:
        _value = rb_float_new(variant.toDouble());
        break;
    case QVariant::UInt:
        _value = rb_float_new(variant.toDouble());
        break;
    case QVariant::LongLong:
        _value = rb_float_new(variant.toDouble());
        break;
    case QVariant::ULongLong:
        _value = rb_float_new(variant.toDouble());
        break;
    case QVariant::Double:
        _value = rb_float_new(variant.toDouble());
        break;
    case QVariant::Char:
        break;
    case QVariant::Map:
        break;
    case QVariant::List:
        break;
    case QVariant::String:
        _value = rb_str_buf_new_cstr(variant.toString().toStdString().c_str());
        break;
    case QVariant::StringList:
        break;
    case QVariant::ByteArray:
        break;
    case QVariant::BitArray:
        break;
    case QVariant::Date:
        break;
    case QVariant::Time:
        break;
    case QVariant::DateTime:
        break;
    case QVariant::Url:
        break;
    case QVariant::Locale:
        break;
    case QVariant::Rect:
        break;
    case QVariant::RectF:
        break;
    case QVariant::Size:
        break;
    case QVariant::SizeF:
        break;
    case QVariant::Line:
        break;
    case QVariant::LineF:
        break;
    case QVariant::Point:
        break;
    case QVariant::PointF:
        break;
    case QVariant::RegExp:
        break;
    case QVariant::RegularExpression:
        break;
    case QVariant::Hash:
        break;
    case QVariant::EasingCurve:
        break;
    case QVariant::Uuid:
        break;
    case QVariant::ModelIndex:
        break;
    case QVariant::LastCoreType: // = QVariant::PersistentModelIndex:
        break;
    case QVariant::Font:
        break;
    case QVariant::Pixmap:
        break;
    case QVariant::Brush:
        break;
    case QVariant::Color:
        break;
    case QVariant::Palette:
        break;
    case QVariant::Image:
        break;
    case QVariant::Polygon:
        break;
    case QVariant::Region:
        break;
    case QVariant::Bitmap:
        break;
    case QVariant::Cursor:
        break;
    case QVariant::KeySequence:
        break;
    case QVariant::Pen:
        break;
    case QVariant::TextLength:
        break;
    case QVariant::TextFormat:
        break;
    case QVariant::Matrix:
        break;
    case QVariant::Transform:
        break;
    case QVariant::Matrix4x4:
        break;
    case QVariant::Vector2D:
        break;
    case QVariant::Vector3D:
        break;
    case QVariant::Vector4D:
        break;
    case QVariant::Quaternion:
        break;
    case QVariant::PolygonF: // = QVariant::LastGuiType
        break;
    case QVariant::Icon:
        break;
    case QVariant::SizePolicy:
        break;
    case QVariant::UserType:
        break;
    }
}

QRubyValue::~QRubyValue() {
}

QRubyValue QRubyValue::functionCall(
    QString functionName,
    QRubyValueList arguments
) {
    VALUE valueArguments[arguments.count()];
    for(int index = 0; index < arguments.count(); index++) {
        valueArguments[index] = arguments[index].value();
    }

    const ID functionID = rb_intern(functionName.toStdString().c_str());

    return rb_funcall2(
        _value,
        functionID,
        arguments.count(),
        (const VALUE*)valueArguments
    );
}

QRubyValue QRubyValue::functionCall(
    QString functionName,
    QVariant argument1,
    QVariant argument2,
    QVariant argument3,
    QVariant argument4,
    QVariant argument5,
    QVariant argument6,
    QVariant argument7,
    QVariant argument8,
    QVariant argument9,
    QVariant argument10,
    QVariant argument11,
    QVariant argument12
) {
    QRubyValueList arguments;
    if(argument1.isValid()) { arguments << argument1; }
    if(argument2.isValid()) { arguments << argument2; }
    if(argument3.isValid()) { arguments << argument3; }
    if(argument4.isValid()) { arguments << argument4; }
    if(argument5.isValid()) { arguments << argument5; }
    if(argument6.isValid()) { arguments << argument6; }
    if(argument7.isValid()) { arguments << argument7; }
    if(argument8.isValid()) { arguments << argument8; }
    if(argument9.isValid()) { arguments << argument9; }
    if(argument10.isValid()) { arguments << argument10; }
    if(argument11.isValid()) { arguments << argument11; }
    if(argument12.isValid()) { arguments << argument12; }

    return functionCall(functionName, arguments);
}

bool QRubyValue::operator==(const QRubyValue& other) {
    return rb_equal(_value, other._value);
}

QRubyValue::ValueType QRubyValue::type() {
    if(!_value) {
        return ValueTypeNone;
    }

    switch(rb_type(_value)) {
    default:
    case RUBY_T_NONE:
        return ValueTypeNone;
        break;
    case RUBY_T_OBJECT:
        return ValueTypeObject;
        break;
    case RUBY_T_CLASS:
        return ValueTypeClass;
        break;
    case RUBY_T_MODULE:
        return ValueTypeModule;
        break;
    case RUBY_T_FLOAT:
        return ValueTypeFloat;
        break;
    case RUBY_T_STRING:
        return ValueTypeString;
        break;
    case RUBY_T_REGEXP:
        return ValueTypeRegExp;
        break;
    case RUBY_T_ARRAY:
        return ValueTypeArray;
        break;
    case RUBY_T_HASH:
        return ValueTypeHash;
        break;
    case RUBY_T_STRUCT:
        return ValueTypeStruct;
        break;
    case RUBY_T_BIGNUM:
        return ValueTypeBigNumber;
        break;
    case RUBY_T_FILE:
        return ValueTypeFile;
        break;
    case RUBY_T_DATA:
        return ValueTypeData;
        break;
    case RUBY_T_MATCH:
        return ValueTypeMatch;
        break;
    case RUBY_T_COMPLEX:
        return ValueTypeComplex;
        break;
    case RUBY_T_RATIONAL:
        return ValueTypeRational;
        break;
    case RUBY_T_NIL:
        return ValueTypeNil;
        break;
    case RUBY_T_TRUE:
        return ValueTypeTrue;
        break;
    case RUBY_T_FALSE:
        return ValueTypeFalse;
        break;
    case RUBY_T_SYMBOL:
        return ValueTypeSymbol;
        break;
    case RUBY_T_FIXNUM:
        return ValueTypeFixedNumber;
        break;
    case RUBY_T_UNDEF:
        return ValueTypeUndefined;
        break;
    case RUBY_T_NODE:
        return ValueTypeNode;
        break;
    case RUBY_T_ICLASS:
        return ValueTypeIncludeClass;
        break;
    case RUBY_T_ZOMBIE:
        return ValueTypeZombie;
        break;
    case RUBY_T_MASK:
        return ValueTypeMask;
        break;
    }
}

bool QRubyValue::isObject()             { return type() == ValueTypeObject; }
bool QRubyValue::isClass()              { return type() == ValueTypeClass; }
bool QRubyValue::isModule()             { return type() == ValueTypeModule; }
bool QRubyValue::isFloat()              { return type() == ValueTypeFloat; }
bool QRubyValue::isString()             { return type() == ValueTypeString; }
bool QRubyValue::isRegularExpression()  { return type() == ValueTypeRegExp; }
bool QRubyValue::isArray()              { return type() == ValueTypeArray; }
bool QRubyValue::isHash()               { return type() == ValueTypeHash; }
bool QRubyValue::isStruct()             { return type() == ValueTypeStruct; }
bool QRubyValue::isBigNumber()          { return type() == ValueTypeBigNumber; }
bool QRubyValue::isFile()               { return type() == ValueTypeFile; }
bool QRubyValue::isData()               { return type() == ValueTypeData; }
bool QRubyValue::isMatch()              { return type() == ValueTypeMatch; }
bool QRubyValue::isComplex()            { return type() == ValueTypeComplex; }
bool QRubyValue::isRational()           { return type() == ValueTypeRational; }
bool QRubyValue::isNil()                { return type() == ValueTypeNil; }
bool QRubyValue::isTrue()               { return type() == ValueTypeTrue; }
bool QRubyValue::isFalse()              { return type() == ValueTypeFalse; }
bool QRubyValue::isSymbol()             { return type() == ValueTypeSymbol; }
bool QRubyValue::isFixedNumber()        { return type() == ValueTypeFixedNumber; }
bool QRubyValue::isUndefined()          { return type() == ValueTypeUndefined; }
bool QRubyValue::isNode()               { return type() == ValueTypeNode; }
bool QRubyValue::isIncludeClass()       { return type() == ValueTypeIncludeClass; }
bool QRubyValue::isZombie()             { return type() == ValueTypeZombie; }
bool QRubyValue::isMask()               { return type() == ValueTypeMask; }

QRubyClass QRubyValue::rubyClass() {
    return QRubyClass::fromRubyValue(QRubyValue(rb_class_of(_value)));
}

QString QRubyValue::className() {
    return rb_obj_classname(_value);
}

QRubyValue QRubyValue::each() {
    return rb_each(_value);
}

QRubyValue QRubyValue::aryEach() {
    return rb_ary_each(_value);
}

QString QRubyValue::toString() {
    VALUE stringValue;
    if(!isString()) {
        stringValue = rb_any_to_s(_value);
    } else {
        stringValue = _value;
    }
    return rb_string_value_cstr(&stringValue);
}

double QRubyValue::toDouble() {
    return rb_float_value(rb_to_float(_value));
}

long QRubyValue::toLong() {
    return rb_num2int(rb_to_int(_value));
}

VALUE QRubyValue::value() {
    return _value;
}

QRubyObject QRubyValue::toObject() {
    if(isObject()) {
        return QRubyObject::fromRubyValue(*this);
    }
    return QRubyObject();
}
