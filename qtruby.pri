#
# Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
#
# This file is part of QtRuby.
#
# QtRuby is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# QtRuby is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public
# License along with QtRuby.
# If not, see <http://www.gnu.org/licenses/>.
#
# It is possible to obtain a commercial license of QtRuby.
# Please contact Jacob Dawid <jacob@omg-it.works>
#

QT += core

INCLUDEPATH += \
    $$PWD

LIBS += \
    -L../qtruby -lqtruby

isEmpty( QTRUBY_LIBS ) {
    message("Define QTRUBY_LIBS in order to specify the ruby library you want to link against.");
    QTRUBY_LIBS = -lruby-2.1
}

isEmpty( QTRUBY_INCLUDEPATH ) {
    message("Define QTRUBY_INCLUDEPATH in order to specify the includepath of the ruby headers.");
    QTRUBY_INCLUDEPATH = /usr/include/x86_64-linux-gnu/ruby-2.1.0 /usr/include/ruby-2.1.0
}

message("USING: QTRUBY_LIBS = $$QTRUBY_LIBS");
message("USING: QTRUBY_INCLUDEPATH = $$QTRUBY_INCLUDEPATH");
LIBS += $$QTRUBY_LIBS
INCLUDEPATH += $$QTRUBY_INCLUDEPATH

