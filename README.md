[![Qt Pods](http://qt-pods.org/assets/logo.png "Qt Pods")](http://qt-pods.org)

Support this and other free software projects of mine by donating bitcoins:
```cpp
1Hk5EkcZRaio4uGXSU453E1bNFTecsZEpt
```

# QtRuby

Execute ruby code seamlessly from within C++/Qt applications.

```cpp
// Qt includes
#include <QCoreApplication>

// QtRuby includes
#include "qruby.h"
#include "qrubyvalue.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);

    QRuby rb;
    rb.printVersion();
    rb.evaluate("(1..10).each do |n| puts n end");

    return 0;
}
```

# Installation and usage

Installation via qt-pods recommended. You can update your version at any time and switch back flawlessly, since it will be embedded as a git submodule. It is not recommended to plain copy the code into your target application. In order to learn more about qt-pods, see here:

https://github.com/cybercatalyst/qt-pods

# License

Licensed under GNU AGPLv3. Available under a commercial license, too.
