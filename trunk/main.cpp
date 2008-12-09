#include "qtwiimote.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWiiMote w;
    w.show();
    return a.exec();
}
