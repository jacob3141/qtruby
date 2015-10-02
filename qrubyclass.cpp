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
#include "qrubyclass.h"

// Qt includes
#include <QDebug>

QRubyClass::QRubyClass(QString className, QRubyValue superClass) :
    QRubyValue() {
    if(superClass.isNil()) {
        superClass = rb_cObject;
    }
    _value = rb_define_class(className.toStdString().c_str(),
                             superClass.value());
}

QRubyClass::QRubyClass(QRubyValue superClass) :
    QRubyValue() {
    if(superClass.isNil()) {
        superClass = rb_cObject;
    }
    _value = rb_class_new(superClass.value());
}

QRubyClass::~QRubyClass() {
}

QString QRubyClass::name() {
    return QRubyValue(rb_class_name(_value)).toString();
}

QRubyClass QRubyClass::classValue(RubyClass rubyClass) {
    switch(rubyClass) {
        case BasicObject:    return fromRubyValue(rb_cBasicObject);      break;
        case Object:         return fromRubyValue(rb_cObject);           break;
        case Array:          return fromRubyValue(rb_cArray);            break;
        case Bignum:         return fromRubyValue(rb_cBignum);           break;
        case Binding:        return fromRubyValue(rb_cBinding);          break;
        case Class:          return fromRubyValue(rb_cClass);            break;
        // Ruby bug: Linker error (undefined reference)
        // case Cont:           return fromRubyValue(rb_cCont);             break;
        case Cont:           qDebug() << "Ruby bug: rb_cCont not exposed."; break;
        case Dir:            return fromRubyValue(rb_cDir);              break;
        case Data:           return fromRubyValue(rb_cData);             break;
        case FalseClass:     return fromRubyValue(rb_cFalseClass);       break;
        case Encoding:       return fromRubyValue(rb_cEncoding);         break;
        case Enumerator:     return fromRubyValue(rb_cEnumerator);       break;
        case File:           return fromRubyValue(rb_cFile);             break;
        case Fixnum:         return fromRubyValue(rb_cFixnum);           break;
        case Float:          return fromRubyValue(rb_cFloat);            break;
        case Hash:           return fromRubyValue(rb_cHash);             break;
        case Integer:        return fromRubyValue(rb_cInteger);          break;
        case IO:             return fromRubyValue(rb_cIO);               break;
        case Match:          return fromRubyValue(rb_cMatch);            break;
        case Method:         return fromRubyValue(rb_cMethod);           break;
        case Module:         return fromRubyValue(rb_cModule);           break;
        case NameErrorMesg:  return fromRubyValue(rb_cNameErrorMesg);    break;
        case NilClass:       return fromRubyValue(rb_cNilClass);         break;
        case Numeric:        return fromRubyValue(rb_cNumeric);          break;
        case Proc:           return fromRubyValue(rb_cProc);             break;
        case Random:         return fromRubyValue(rb_cRandom);           break;
        case Range:          return fromRubyValue(rb_cRange);            break;
        case Rational:       return fromRubyValue(rb_cRational);         break;
        case Complex:        return fromRubyValue(rb_cComplex);          break;
        case Regexp:         return fromRubyValue(rb_cRegexp);           break;
        case Stat:           return fromRubyValue(rb_cStat);             break;
        case String:         return fromRubyValue(rb_cString);           break;
        case Struct:         return fromRubyValue(rb_cStruct);           break;
        case Symbol:         return fromRubyValue(rb_cSymbol);           break;
        case Thread:         return fromRubyValue(rb_cThread);           break;
        case Time:           return fromRubyValue(rb_cTime);             break;
        case TrueClass:      return fromRubyValue(rb_cTrueClass);        break;
        case UnboundMethod:  return fromRubyValue(rb_cUnboundMethod);    break;
    };

    return QRubyClass();
}

QRubyClass QRubyClass::fromRubyValue(QRubyValue rubyValue) {
    QRubyClass rubyClass;
    if(rubyClass.isClass()) {
        rubyClass._value = rubyValue.value();
    } else {
        rubyClass._value = Qnil;
    }
    return rubyClass;
}
