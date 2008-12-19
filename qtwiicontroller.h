#ifndef QTWIICONTROLLER_H
#define QTWIICONTROLLER_H

#include <QList>
#include "qtwiiuse.h"
#include <QWidget>
#include <QPushButton>

class QtWiiController : public QWidget
{
    Q_OBJECT

    public:
        QtWiiController ();

    private:
        QList<QtWiiUse*> lista;
        int numMax;
        int atual;

    private slots:
        void connectNewWii();
        void deleteWiimote (QtWiiUse*);
};

#endif // QTWIICONTROLLER_H
