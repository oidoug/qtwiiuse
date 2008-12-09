#include "qtwiimote.h"

QtWiiMote::QtWiiMote(QWidget *parent)
    : QWidget(parent), WiiMoteEvent()
{
	ui.setupUi(this);

	connect(ui.connectButton, SIGNAL(clicked()), this, SLOT(connectWiiMote()));
}

QtWiiMote::~QtWiiMote()
{
	this->wiimote->terminate();
}

void QtWiiMote::connectWiiMote() {
	this->connectDevices();
}

/**
 * Virtual method called when a action is generated. Similar to QEvent events.
 */
void QtWiiMote::wiimoteButtonEvent(WiiMoteEvent *event) {
	if(event->activeActions[WiiMoteEvent::ButtonA]) qDebug("A PRESSED.");
}

/**
 * Virtual method called every loop to refresh the position of the infra red
 * virtual cursor.
 */
void QtWiiMote::wiimoteCursorEvent(WiiMoteEvent *event) {
	qDebug("Cursor: %d - %d", event->cursorPos().x(), event->cursorPos().y());
}
