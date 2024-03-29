#ifndef WIITHREAD_H
#define WIITHREAD_H

#include <QtGui/QWidget>
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
        bool stop;

    public slots:
        void alternaVibrador(int);
        void alternaAcc(int);
        void disconnectWiimote();

    signals:
        void wiimoteShutdown ();
        void connectionClosed();
};

#endif // WIITHREAD_H
