/*
 * wiimotethread.cpp
 *
 *  Created on: Oct 22, 2008
 *      Author: das
 */

#include "wiimotethread.h"

WiiMoteThread::WiiMoteThread(QtWiiMote *widget) : QThread(widget) {
	this->widget = widget;
	this->found_devices = 0;
	this->connected_devices = 0;
	this->connection_error = false;
	howmany = 1;
	timeout = 10;
}

void WiiMoteThread::run() {
	widget->getUi()->connectLabel->setText("Press 1 & 2");

	this->wiimotes = wiiuse_init(howmany);

	found_devices = wiiuse_find(wiimotes, howmany, timeout);
	if (!found_devices) {
		qWarning("No Wii remote found.");
		connection_error= false;
		widget->getUi()->connectLabel->setText("No Device Found");
		return;
	}

	connected_devices = wiiuse_connect(wiimotes, howmany);
	if (connected_devices) {
		qDebug("Connected to %i wiimotes (of %i found).", this->connected_devices, this->found_devices);
		connection_error = true;
		widget->getUi()->connectLabel->setText("Connected");
	}
	else {
		qWarning("Failed to connect to any wiimote.");
		connection_error = false;
		widget->getUi()->connectLabel->setText("Connection Fail");
		return;
	}

	while (1) {
		if (wiiuse_poll(wiimotes, howmany)) {
			/*
			 *	This happens if something happened on any wiimote.
			 *	So go through each one and check if anything happened.
			 */
			for (int i = 0; i < howmany; i++) {
				switch (wiimotes[i]->event) {
					case WIIUSE_EVENT:
						/* a generic event occured */
						handle_event(wiimotes[i]);
						break;

					case WIIUSE_DISCONNECT:
					case WIIUSE_UNEXPECTED_DISCONNECT:
						/* the wiimote disconnected */
						handle_disconnect(wiimotes[i]);
						break;
				}
			}
		}
	}
}

void WiiMoteThread::handle_disconnect(wiimote* wm) {
	qDebug("Connection interrupted or POWER button pressed.");
}

void WiiMoteThread::handle_event(struct wiimote_t* wm) {
	/* if a button is pressed, report it */
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_A))		qDebug("A pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_B))		qDebug("B pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_UP))		qDebug("UP pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_DOWN))	qDebug("DOWN pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_LEFT))	qDebug("LEFT pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_RIGHT))	qDebug("RIGHT pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_MINUS))	qDebug("MINUS pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_PLUS))	qDebug("PLUS pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_ONE))		qDebug("ONE pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_TWO))		qDebug("TWO pressed\n");
	if (IS_PRESSED(wm, WIIMOTE_BUTTON_HOME))	qDebug("HOME pressed\n");

	/*
	 *	Pressing minus will tell the wiimote we are no longer interested in movement.
	 *	This is useful because it saves battery power.
	 */
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_MINUS))
		wiiuse_motion_sensing(wm, 0);

	/*
	 *	Pressing plus will tell the wiimote we are interested in movement.
	 */
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_PLUS))
		wiiuse_motion_sensing(wm, 1);

	/*
	 *	Pressing B will toggle the rumble
	 *
	 *	if B is pressed but is not held, toggle the rumble
	 */
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_B))
		wiiuse_toggle_rumble(wm);

	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_UP))
		wiiuse_set_ir(wm, 1);
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_DOWN))
		wiiuse_set_ir(wm, 0);

	/* if the accelerometer is turned on then print angles */
	if (WIIUSE_USING_ACC(wm)) {
		widget->getUi()->rollSlider->setValue(wm->orient.roll);
		widget->getUi()->pitchSlider->setValue(wm->orient.pitch);
	}

	/*
	 *	If IR tracking is enabled then print the coordinates
	 *	on the virtual screen that the wiimote is pointing to.
	 *
	 *	Also make sure that we see at least 1 dot.
	 */
	if (WIIUSE_USING_IR(wm)) {
		int i = 0;

		/* go through each of the 4 possible IR sources */
		for (; i < 4; ++i) {
			/* check if the source is visible */
			if (wm->ir.dot[i].visible)
				qDebug("IR source %i: (%u, %u)\n", i, wm->ir.dot[i].x, wm->ir.dot[i].y);
		}

		qDebug("IR cursor: (%u, %u)\n", wm->ir.x, wm->ir.y);
		qDebug("IR z distance: %f\n", wm->ir.z);
	}

}
