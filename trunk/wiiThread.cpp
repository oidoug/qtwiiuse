#include "WiiThread.h"

WiiThread::WiiThread (QtWiiUse* parent)
{
    this->parent = parent;
    stop=0;
}


void WiiThread::run()
{
    Ui::QtWiiUseClass* tela = parent->getUi();
    connect (tela->rumble_checkbox, SIGNAL (stateChanged(int)), this, SLOT (alternaVibrador(int)));
    connect (tela->acc_checkbox, SIGNAL (stateChanged(int)), this, SLOT (alternaAcc(int)));
    connect (tela->disconnect_button, SIGNAL (clicked()), this, SLOT (disconnectWiimote()));
    connect (this, SIGNAL (wiimoteShutdown()), this, SLOT (disconnectWiimote()));
    connect (this, SIGNAL (finished()), parent, SLOT (reconnectWii()));
    int numConectados = 0;
    wiimotes = wiiuse_init(1);
    int found_devices = 0;
    while (found_devices==0)
        found_devices = wiiuse_find(wiimotes, 1, 10);
    while (numConectados==0)
        numConectados = wiiuse_connect(wiimotes, 1);
    tela->connect_button->setEnabled(0);
    tela->disconnect_button->setEnabled(1);
    tela->label->setText("Conectado");
    tela->acc_checkbox->setEnabled(1);
    tela->rumble_checkbox->setEnabled(1);
    tela->ir_checkbox->setEnabled(1);
    int rool, pitch;
    while (!stop) {
        if (wiiuse_poll(wiimotes, 1))
        {
            if (wiimotes[0]->event == WIIUSE_EVENT)
            {
                if (WIIUSE_USING_ACC(wiimotes[0])) {
                    rool = wiimotes[0]->orient.a_roll;
                    pitch = wiimotes[0]->orient.a_pitch;
                    if (tela->horizontalSlider->value() != rool) {
                       tela->roll_value->setText(QString::number(rool));
                       tela->horizontalSlider->setValue(rool);
                   }
                    if (tela->horizontalSlider_3->value() != pitch)
                        tela->horizontalSlider_3->setValue(pitch);
                    //printf("wiimote yaw   = %f\n", wiimotes[0]->orient.yaw);
                }
                if (WIIUSE_USING_IR(wiimotes[0])) {
                    int i = 0;
                    for (; i < 4; ++i)
                    {
                            if (wiimotes[0]->ir.dot[i].visible)
                                    printf("IR source %i: (%u, %u)\n", i, wiimotes[0]->ir.dot[i].x, wiimotes[0]->ir.dot[i].y);
                    }
                    printf("IR cursor: (%u, %u)\n", wiimotes[0]->ir.x, wiimotes[0]->ir.y);
                    printf("IR z distance: %f\n", wiimotes[0]->ir.z);
                }
            }
            else if (wiimotes[0]->event == WIIUSE_DISCONNECT)
                emit wiimoteShutdown();
        }
    }
}

void WiiThread::alternaVibrador(int state)
{
    wiiuse_rumble(wiimotes[0], state);
}

void WiiThread::alternaAcc(int state)
{
    wiiuse_motion_sensing(wiimotes[0], state);
}

void WiiThread::disconnectWiimote()
{
    Ui::QtWiiUseClass *temp = parent->getUi();
    temp->connect_button->setEnabled(1);
    temp->disconnect_button->setEnabled(0);
    temp->label->setText("Desconectado");
    stop = 1;
    temp->acc_checkbox->setChecked(0);
    temp->rumble_checkbox->setChecked(0);
    temp->ir_checkbox->setChecked(0);
    temp->acc_checkbox->setEnabled(0);
    temp->rumble_checkbox->setEnabled(0);
    temp->ir_checkbox->setEnabled(0);
    if (!WIIUSE_DISCONNECT)
        wiiuse_cleanup (wiimotes, 1);
    else
        emit connectionClosed();
}
