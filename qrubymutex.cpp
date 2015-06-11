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
#include "qrubymutex.h"

QRubyMutex::QRubyMutex() :
    QRubyValue() {
    _value = rb_mutex_new();
}

QRubyMutex::~QRubyMutex() {
}

bool QRubyMutex::isLocked() {
    return Qtrue == rb_mutex_locked_p(_value);
}

bool QRubyMutex::tryLock() {
    return Qtrue == rb_mutex_trylock(_value);
}

void QRubyMutex::lock() {
    rb_mutex_lock(_value);
}

void QRubyMutex::unlock() {
    rb_mutex_unlock(_value);
}
