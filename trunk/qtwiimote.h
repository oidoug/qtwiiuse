#ifndef QTWIIMOTE_H
#define QTWIIMOTE_H

#include <QtGui/QWidget>
#include <QThread>
#include "ui_qtwiimote.h"

#include "wmsupport/wiimoteevent.h"

class QtWiiMote : public QWidget, public WiiMoteEvent
{
    Q_OBJECT

public:
    QtWiiMote(QWidget *parent = 0);
    ~QtWiiMote();

    inline Ui::QtWiiMoteClass *getUi() {return &ui;}

	/**
	 * method called when a action is generated. Similar to QEvent events.
	 */
	void wiimoteButtonEvent(WiiMoteEvent *event);

	/**
	 * method called every loop to refresh the position of the infra red
	 * virtual cursor.
	 */
	void wiimoteCursorEvent(WiiMoteEvent *event);

private:
    Ui::QtWiiMoteClass ui;

public slots:
	/**
	 * Will connect the howmany numbers of wii remotes.
	 */
	void connectWiiMote();

signals:
	void connected(int);
	void fail();
};

#endif // QTWIIMOTE_H
