#include <QtGui/QApplication>
#include "qtwiicontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWiiController w;
    w.show();
    return a.exec();
}
