#include <QtGui/QApplication>
#include "qtwiiuse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWiiUse w;
    w.show();
    return a.exec();
}
