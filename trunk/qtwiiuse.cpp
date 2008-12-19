#include "qtwiiuse.h"
#include <iostream>
#include <QMessageBox>
#include "WiiThread.h"
#include "qtwiicontroller.h"

using namespace std;

QtWiiUse::QtWiiUse(QtWiiController *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
{
    this->parent = parent;
    ui.setupUi(this);
    ui.disconnect_button->setDisabled(1);
    ui.horizontalSlider->setEnabled(0);
    ui.horizontalSlider_3->setEnabled(0);
    ui.horizontalSlider_4->setEnabled(0);
    ui.horizontalSlider_5->setEnabled(0);
    ui.horizontalSlider_6->setEnabled(0);
    ui.acc_checkbox->setEnabled(0);
    ui.rumble_checkbox->setEnabled(0);
    ui.ir_checkbox->setEnabled(0);
    connect (this->ui.connect_button, SIGNAL (clicked()), this, SLOT (displayConnectMessage()));
    connect (this->ui.disconnect_button, SIGNAL (clicked()), this, SLOT (removeWiimote()));
    connect (this, SIGNAL (callThreadStart()), this, SLOT (connectWii()));
    thread = 0;
}

void QtWiiUse::removeWiimote()
{
    emit removeWii (this);
}

QtWiiUse::~QtWiiUse()
{
}

void QtWiiUse::displayConnectMessage()
{
    if (this->thread==0)
    {
    ui.label->setText("Aperte 1 e 2");
    emit callThreadStart();
    }
}

void QtWiiUse::connectWii()
{
    if (thread == NULL) {
    thread = new WiiThread(this);
    connect (this->thread, SIGNAL (connectionClosed()), this, SLOT (removeWiimote()));
    thread->start();
    }/*
    else {
        QtWiiUse *temp = new QtWiiUse (this);
        temp->show();
    }*/
}

void QtWiiUse::reconnectWii ()
{
    delete thread;
}
