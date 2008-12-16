#include "qtwiiuse.h"
#include <iostream>
#include <QMessageBox>
#include "WiiThread.h"

using namespace std;

QtWiiUse::QtWiiUse(QWidget *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);
    ui.disconnect_button->setDisabled(1);
    ui.horizontalSlider->setEnabled(0);
    ui.horizontalSlider_3->setEnabled(0);
    ui.horizontalSlider_4->setEnabled(0);
    ui.horizontalSlider_5->setEnabled(0);
    ui.horizontalSlider_6->setEnabled(0);
    connect (this->ui.connect_button, SIGNAL (clicked()), this, SLOT (displayConnectMessage()));
    connect (this, SIGNAL (callThreadStart()), this, SLOT (connectWii()));
    thread = new WiiThread(this);
}

QtWiiUse::~QtWiiUse()
{
}

void QtWiiUse::displayConnectMessage()
{
    QMessageBox* mensagem = new QMessageBox ();
    mensagem->setText("Aperte os botoes 1 e 2");
    mensagem->addButton("Ok", QMessageBox::AcceptRole);
    mensagem->show();
    emit callThreadStart();
}

void QtWiiUse::connectWii()
{
    thread->start();
}
