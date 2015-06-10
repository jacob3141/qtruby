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

// Ruby includes
#include <ruby.h>

// Own includes
#include "qruby.h"

QRuby::QRuby(QObject *parent) :
    QObject(parent) {
    ruby_init();
    ruby_setup();
}

QRuby::~QRuby() {
    ruby_cleanup(0);
}

QRubyValue QRuby::newObject() {
    return QRubyValue(rb_newobj());
}

QRubyValue QRuby::evaluate(QString code) {
    return QRubyValue(rb_eval_string_protect(code.toStdString().c_str(), 0));
}

QRubyValue QRuby::errorInfo() {
    return QRubyValue(rb_errinfo());
}

void QRuby::setErrorInfo(QRubyValue rubyValue) {
    rb_set_errinfo(rubyValue.value());
}

void QRuby::printVersion() {
    ruby_show_version();
}

void QRuby::printCopyrightNotice() {
    ruby_show_copyright();
}
