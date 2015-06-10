QT += core

INCLUDEPATH += \
    $$PWD

LIBS += \
    -L../qtruby -lqtruby

LIBS += -lruby-2.2

INCLUDEPATH += \
  /usr/include/x86_64-linux-gnu/ruby-2.2.0 \
  /usr/include/ruby-2.2.0
