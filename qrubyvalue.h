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

#pragma once

// Ruby includes
#include "ruby.h"

// Qt includes
#include <QString>
#include <QList>
#include <QVariant>

class QRubyId;

class QRubyObject;
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

class QRubyValue;
typedef QList<QRubyValue> QRubyValueList;

class QRubyValue {
public:
    enum SpecialConstants {
        False           = RUBY_Qfalse,
        True            = RUBY_Qtrue,
        Nil             = RUBY_Qnil,
        Undefined       = RUBY_Qundef,

        ImmediateMask   = RUBY_IMMEDIATE_MASK,
        FixnumFlag      = RUBY_FIXNUM_FLAG,
        FlonumMask      = RUBY_FLONUM_MASK,
        FlonumFlag      = RUBY_FLONUM_FLAG,
        SymbolFlag      = RUBY_SYMBOL_FLAG,
        SpecialShift    = RUBY_SPECIAL_SHIFT
    };

    enum ValueType {
        ValueTypeNone,
        ValueTypeObject,
        ValueTypeClass,
        ValueTypeModule,
        ValueTypeFloat,
        ValueTypeString,
        ValueTypeRegExp,
        ValueTypeArray,
        ValueTypeHash,
        ValueTypeStruct,
        ValueTypeBigNumber,
        ValueTypeFile,
        ValueTypeData,
        ValueTypeMatch,
        ValueTypeComplex,
        ValueTypeRational,
        ValueTypeNil,
        ValueTypeTrue,
        ValueTypeFalse,
        ValueTypeSymbol,
        ValueTypeFixedNumber,
        ValueTypeUndefined,
        ValueTypeNode,
        ValueTypeIncludeClass,
        ValueTypeZombie,
        ValueTypeMask
    };

    QRubyValue(const QRubyValue& other);

    QRubyValue(VALUE value = Qnil);
    QRubyValue(QVariant variant);

    ~QRubyValue();


    /** Performs a function call. */
    QRubyValue functionCall(
        QString functionName,
        QRubyValueList arguments = QRubyValueList()
    );

    QRubyValue functionCall(
        QString functionName,
        QVariant argument1,
        QVariant argument2 = QVariant::Invalid,
        QVariant argument3 = QVariant::Invalid,
        QVariant argument4 = QVariant::Invalid,
        QVariant argument5 = QVariant::Invalid,
        QVariant argument6 = QVariant::Invalid,
        QVariant argument7 = QVariant::Invalid,
        QVariant argument8 = QVariant::Invalid,
        QVariant argument9 = QVariant::Invalid,
        QVariant argument10 = QVariant::Invalid,
        QVariant argument11 = QVariant::Invalid,
        QVariant argument12 = QVariant::Invalid
    );

    bool operator==(const QRubyValue& other);

    ValueType type();

    bool isObject();
    bool isClass();
    bool isModule();
    bool isFloat();
    bool isString();
    bool isRegularExpression();
    bool isArray();
    bool isHash();
    bool isStruct();
    bool isBigNumber();
    bool isFile();
    bool isData();
    bool isComplex();
    bool isRational();

    bool isSymbol();
    bool isFixedNumber();
    bool isUndefined();
    bool isNode();
    bool isIncludeClass();
    bool isZombie();
    bool isMask();

    bool isMatch();
    bool isNil();
    bool isTrue();
    bool isFalse();

    QRubyClass rubyClass();
    QString className();

    QRubyValue each();
    QRubyValue aryEach();

    QString toString();
    double toDouble();
    qint64 toLong();

    VALUE value();

    QRubyObject toObject();

protected:
    VALUE _value;
};

#define AS_BOOL(value) (QRubyValue((value)).isTrue())
