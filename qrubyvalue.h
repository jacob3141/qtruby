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

#ifndef QRUBYVALUE_H
#define QRUBYVALUE_H

// Ruby includes
#include "ruby.h"

// Qt includes
#include <QString>
class QRubyId;

class QRubyValue {
public:
    enum ValueType {
        ValueTypeNone,
        ValueTypeObject,
        ValueTypeClass,
        ValueTypeModule,
        ValueTypeFloat,
        ValueTypeString,
        ValueTypeRegularExpression,
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

    QRubyValue(VALUE value = Qnil);
    QRubyValue(QString value);
    QRubyValue(double value);

    ~QRubyValue();

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
    bool isMatch();
    bool isComplex();
    bool isRational();
    bool isNil();
    bool isTrue();
    bool isFalse();
    bool isSymbol();
    bool isFixedNumber();
    bool isUndefined();
    bool isNode();
    bool isIncludeClass();
    bool isZombie();
    bool isMask();

    QRubyValue classValue();
    QString className();

    QRubyValue each();
    QRubyValue aryEach();

    QRubyId toRubyId();

    QString toString();
    double toNumber();

    VALUE value();

protected:
    VALUE _value;
};

#endif // QRUBYVALUE_H
