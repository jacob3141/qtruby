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
#include "qrubyobject.h"
#include "qrubyid.h"
#include "qrubyclass.h"

QRubyObject::QRubyObject() :
    QRubyValue() {
    _value = rb_newobj();
}

bool QRubyObject::isInstanceOf(QRubyClass classValue) {
    return AS_BOOL(rb_obj_is_instance_of(_value, classValue.value()));
}

bool QRubyObject::isKindOf(QRubyClass classValue) {
    return AS_BOOL(rb_obj_is_kind_of(_value, classValue.value()));
}

bool QRubyObject::respondsTo(QRubyId rubyId, bool includePrivate) {
    return rb_obj_respond_to(_value, rubyId.id(), includePrivate ? Qtrue : Qfalse);
}

QRubyValue QRubyObject::instanceEval(QRubyValueList arguments) {
    VALUE valueArguments[arguments.count()];
    for(int index = 0; index < arguments.count(); index++) {
        valueArguments[index] = arguments[index].value();
    }

    return rb_obj_instance_eval(arguments.count(), valueArguments, _value);
}

QRubyValue QRubyObject::instanceExec(QRubyValueList arguments) {
    VALUE valueArguments[arguments.count()];
    for(int index = 0; index < arguments.count(); index++) {
        valueArguments[index] = arguments[index].value();
    }

    return rb_obj_instance_exec(arguments.count(), valueArguments, _value);
}

bool QRubyObject::isMethod() {
    return AS_BOOL(rb_obj_is_method(_value));
}

bool QRubyObject::isProc() {
    return AS_BOOL(rb_obj_is_proc(_value));
}

QRubyValue QRubyObject::method(QRubyValue methodName) {
    return rb_obj_method(_value, methodName.value());
}

int QRubyObject::methodArity(QRubyId id) {
    return rb_obj_method_arity(_value, id.id());
}

QRubyValue QRubyObject::initCopy(QRubyValue origin) {
    return rb_obj_init_copy(_value, origin.value());
}

QRubyValue QRubyObject::alloc() {
    return rb_obj_alloc(_value);
}

QRubyObject QRubyObject::clone() {
    return QRubyValue(rb_obj_clone(_value)).toObject();
}

QRubyObject QRubyObject::dup() {
    return QRubyValue(rb_obj_dup(_value)).toObject();
}

QRubyValue QRubyObject::taint() {
    return rb_obj_taint(_value);
}

QRubyValue QRubyObject::untaint() {
    return rb_obj_untaint(_value);
}

QRubyValue QRubyObject::tainted() {
    return rb_obj_tainted(_value);
}

QRubyValue QRubyObject::trust() {
    return rb_obj_trust(_value);
}

QRubyValue QRubyObject::untrust() {
    return rb_obj_untrust(_value);
}

QRubyValue QRubyObject::untrusted() {
    return rb_obj_untrusted(_value);
}

QRubyObject QRubyObject::freeze() {
    return fromRubyValue(rb_obj_freeze(_value));
}

bool QRubyObject::isFrozen() {
    return AS_BOOL(rb_obj_frozen_p(_value));
}

QRubyId QRubyObject::id() {
    return rb_obj_id(_value);
}

QRubyClass QRubyObject::rubyClass() {
    return QRubyClass::fromRubyValue(rb_obj_class(_value));
}

QRubyObject QRubyObject::fromRubyValue(QRubyValue rubyValue) {
    QRubyObject rubyObject;
    if(rubyValue.isObject()) {
        rubyObject._value = rubyValue.value();
    } else {
        rubyObject._value = Qnil;
    }
    return rubyObject;
}
