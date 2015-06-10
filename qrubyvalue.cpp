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

QRubyValue::QRubyValue(VALUE value) :
    _value(value) {
}

QRubyValue::~QRubyValue() {
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
        return ValueTypeRegularExpression;
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

