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
#include <QObject>

// Own includes
#include "qrubyvalue.h"

class QRuby : public QObject {
    Q_OBJECT
public:
    enum RubyStdIO {
        StdIn,
        StdOut,
        StdErr
    };

    QRuby(int &argc, char **argv, QObject *parent = 0);
    ~QRuby();

    QRubyValue rubyStdIO(RubyStdIO stdIO);

    /** Create a new binding. */
    QRubyValue newBinding();
    /** @return the top level binding. */
    QRubyValue topLevelBinding();

    /** Requires the specified module. */
    QRubyValue require(QString name);
    /** Evaluates the ruby code with the given binding. */
    QRubyValue eval(QString code, QRubyValue binding = QRubyValue());
    /** Evaluates the ruby code with the top level binding. */
    QRubyValue evalGlobally(QString code);

    QRubyValue errorInfo();
    void setErrorInfo(QRubyValue rubyValue);

    /** Prints the current ruby version. */
    void printVersion();
    /** Prints a copyright notice. */
    void printCopyrightNotice();
};

