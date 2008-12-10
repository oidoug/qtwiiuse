#ifndef QTWIIUSE_H
#define QTWIIUSE_H

#include <QtGui/QWidget>
#include "ui_qtwiiuse.h"

class QtWiiUse : public QWidget
{
    Q_OBJECT

public:
    QtWiiUse(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QtWiiUse();

private:
    Ui::QtWiiUseClass ui;
};

#endif // QTWIIUSE_H
