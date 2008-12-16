#include "WiiThread.h"

WiiThread::WiiThread (QtWiiUse* parent)
{
    this->parent = parent;
}


void WiiThread::run()
{
    Ui::QtWiiUseClass* tela = parent->getUi();
    connect (tela->rumble_checkbox, SIGNAL (clicked()), this, SLOT (alternaVibrador()));        
    int numConectados;
    wiimotes = wiiuse_init(1);
    int found_devices;
    found_devices = wiiuse_find(wiimotes, 1, 10);
    numConectados = wiiuse_connect(wiimotes, 1);
}

void WiiThread::alternaVibrador()
{
    wiiuse_toggle_rumble(wiimotes[0]);
}

void WiiThread::readData()
{
}
