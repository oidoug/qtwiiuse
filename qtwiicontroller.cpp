#include "qtwiicontroller.h"

QtWiiController::QtWiiController ()
{
    QPushButton* conectar = new QPushButton(this);
    conectar->setText("Conectar novo controle Wii");
    connect (conectar, SIGNAL (clicked()), this, SLOT (connectNewWii()));    
    numMax = 2;
    atual = 0;
}

void QtWiiController::connectNewWii()
{
    if (atual < numMax)
    {
        QtWiiUse *temp = new QtWiiUse();
        connect (temp, SIGNAL (removeWii(QtWiiUse*)), this, SLOT (deleteWiimote(QtWiiUse*)));
        lista.insert(atual,temp);
        atual++;
        temp->show();
    }
}

void QtWiiController::deleteWiimote (QtWiiUse* disconnected)
{
    disconnected->close();
    lista.removeOne(disconnected);
}
