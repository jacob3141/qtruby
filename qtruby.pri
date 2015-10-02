QT += core

INCLUDEPATH += \
    $$PWD

LIBS += \
    -L../qtruby -lqtruby

LIBS += -lruby-2.1

INCLUDEPATH += \
  /usr/include/x86_64-linux-gnu/ruby-2.1.0 \
  /usr/include/ruby-2.1.0
