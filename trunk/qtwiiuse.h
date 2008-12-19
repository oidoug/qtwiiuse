#ifndef QTWIIUSE_H
#define QTWIIUSE_H

#include <QtGui/QWidget>
#include "ui_qtwiiuse.h"
#include <wiiuse.h>

class WiiThread;
class QtWiiController;

class QtWiiUse : public QWidget
{
    Q_OBJECT

public:
    QtWiiUse(QtWiiController *parent = 0, Qt::WFlags flags = 0);
    ~QtWiiUse();
     inline Ui::QtWiiUseClass* getUi ()
    {
        return &ui;
    }

private:
    Ui::QtWiiUseClass ui;
    WiiThread *thread;
    QtWiiController *parent;

private slots:
    void displayConnectMessage();
    void connectWii();
    void reconnectWii();
    void removeWiimote();

signals:
    void callThreadStart();
    void removeWii (QtWiiUse*);
};

#endif // QTWIIUSE_H
