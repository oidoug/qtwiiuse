#ifndef WIITHREAD_H
#define WIITHREAD_H

#include <QThread>
#include "wiiuse.h"
#include "qtwiiuse.h"

class WiiThread : public QThread
{

    Q_OBJECT

    public:
        void run();
        WiiThread (QtWiiUse* parent);

    private:
        wiimote** wiimotes;
        QtWiiUse *parent;
        void readData();

    public slots:
        void alternaVibrador();
};

#endif // WIITHREAD_H
