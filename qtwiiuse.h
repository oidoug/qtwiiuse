#ifndef QTWIIUSE_H
#define QTWIIUSE_H

#include <QtGui/QWidget>
#include "ui_qtwiiuse.h"
#include <wiiuse.h>

class WiiThread;

class QtWiiUse : public QWidget
{
    Q_OBJECT

public:
    QtWiiUse(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QtWiiUse();
     inline Ui::QtWiiUseClass* getUi ()
    {
        return &ui;
    }

private:
    Ui::QtWiiUseClass ui;
    WiiThread *thread;
    
private slots:
    void displayConnectMessage();
    void connectWii();
    void reconnectWii();

signals:
    void callThreadStart();
};

#endif // QTWIIUSE_H
