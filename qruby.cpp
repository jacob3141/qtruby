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
#include <ruby/intern.h>

// Own includes
#include "qruby.h"
#include "qrubyclass.h"

QRuby::QRuby(int &argc, char **argv, QObject *parent) :
    QObject(parent) {
    ruby_sysinit(&argc, &argv);
    RUBY_INIT_STACK;
    ruby_init();
    ruby_init_loadpath();
}

QRuby::~QRuby() {
    ruby_finalize();
}


QRubyValue QRuby::rubyStdIO(RubyStdIO stdIO) {
    switch(stdIO) {
    case StdIn:     return rb_stdin;    break;
    case StdOut:    return rb_stdout;   break;
    case StdErr:    return rb_stderr;   break;
    }

    return QRubyValue();
}

QRubyValue QRuby::newBinding() {
    return QRubyValue(rb_binding_new());
}

QRubyValue QRuby::topLevelBinding() {
    return QRubyValue(rb_const_get(rb_cObject, rb_intern("TOPLEVEL_BINDING")));
}

QRubyValue QRuby::require(QString name) {
    return rb_require(name.toStdString().c_str());
}

QRubyValue QRuby::eval(QString code, QRubyValue binding) {
    QRubyValueList arguments;
    arguments << QRubyValue(code) << binding;
    return functionCall(Qnil, "eval", arguments);
}

QRubyValue QRuby::evalGlobally(QString code) {
    return eval(code, topLevelBinding());
}

QRubyValue QRuby::functionCall(
    QRubyValue target,
    QString functionName,
    QRubyValueList arguments
) {
    VALUE valueArguments[arguments.count()];
    for(int index = 0; index < arguments.count(); index++) {
        valueArguments[index] = arguments[index].value();
    }

    const ID functionID = rb_intern(functionName.toStdString().c_str());

    return rb_funcall2(
        target.value(),
        functionID,
        arguments.count(),
        (const VALUE*)valueArguments
    );
}

QRubyValue QRuby::errorInfo() {
    return rb_errinfo();
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
