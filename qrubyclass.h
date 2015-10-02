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

// Own includes
#include "qrubyvalue.h"

/*
 * TODO: Map these methods:
VALUE rb_class_boot(VALUE);
VALUE rb_class_new(VALUE);
VALUE rb_class_inherited(VALUE, VALUE);
VALUE rb_class_instance_methods(int, VALUE*, VALUE);
VALUE rb_class_public_instance_methods(int, VALUE*, VALUE);
VALUE rb_class_protected_instance_methods(int, VALUE*, VALUE);
VALUE rb_class_private_instance_methods(int, VALUE*, VALUE);
VALUE rb_class_new_instance(int, VALUE*, VALUE);
VALUE rb_class_real(VALUE);
VALUE rb_class_inherited_p(VALUE, VALUE);
VALUE rb_class_superclass(VALUE);
VALUE rb_class_get_superclass(VALUE);
VALUE rb_class_path(VALUE);
VALUE rb_class_path_cached(VALUE);
VALUE rb_class_name(VALUE);
*/
class QRubyClass :
    public QRubyValue {
public:
    enum RubyClass {
        BasicObject,
        Object,
        Array,
        Bignum,
        Binding,
        Class,
        Cont,
        Dir,
        Data,
        FalseClass,
        Encoding,
        Enumerator,
        File,
        Fixnum,
        Float,
        Hash,
        Integer,
        IO,
        Match,
        Method,
        Module,
        NameErrorMesg,
        NilClass,
        Numeric,
        Proc,
        Random,
        Range,
        Rational,
        Complex,
        Regexp,
        Stat,
        String,
        Struct,
        Symbol,
        Thread,
        Time,
        TrueClass,
        UnboundMethod
    };

    QRubyClass(QString name, QRubyValue superClass = QRubyValue());
    QRubyClass(QRubyValue superClass = QRubyValue());
    ~QRubyClass();

    QString name();


    static QRubyClass classValue(RubyClass rubyClass);
    static QRubyClass fromRubyValue(QRubyValue rubyValue);
};
