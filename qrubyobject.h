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
 * TODO: Wrap these object methods:
void rb_obj_call_init(VALUE, int, VALUE*);
VALUE rb_obj_singleton_methods(int, VALUE*, VALUE);
VALUE rb_obj_instance_variables(VALUE);
VALUE rb_obj_remove_instance_variable(VALUE, VALUE);
*/
class QRubyObject :
    public QRubyValue {
public:
    QRubyObject();

    bool isInstanceOf(QRubyClass rubyClass);
    bool isKindOf(QRubyClass rubyClass);
    bool isMethod();
    bool isProc();

    bool respondsTo(QRubyId rubyId, bool includePrivate = true);

    QRubyValue instanceEval(QRubyValueList arguments);
    QRubyValue instanceExec(QRubyValueList arguments);

    QRubyValue method(QRubyValue methodName);
    int methodArity(QRubyId id);

    QRubyValue initCopy(QRubyValue origin);
    QRubyValue alloc();
    QRubyObject clone();
    QRubyObject dup();

    QRubyValue taint();
    QRubyValue untaint();
    QRubyValue tainted();

    QRubyValue trust();
    QRubyValue untrust();
    QRubyValue untrusted();

    QRubyObject freeze();
    bool isFrozen();

    QRubyId id();
    QRubyClass rubyClass();

    static QRubyObject fromRubyValue(QRubyValue rubyValue);
};

