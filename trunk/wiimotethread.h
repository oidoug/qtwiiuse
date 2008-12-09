/*
 * wiimotethread.h
 *
 *  Created on: Oct 22, 2008
 *      Author: das
 */

#ifndef WIIMOTETHREAD_H_
#define WIIMOTETHREAD_H_

#include "qtwiimote.h"

class WiiMoteThread : public QThread
{
public:
	WiiMoteThread(QtWiiMote *widget);
	void run();
    void handle_event(struct wiimote_t* wm);
    void handle_disconnect(wiimote* wm);

    QtWiiMote *widget;

    wiimote_t** wiimotes;

    int found_devices;
    int connected_devices;
    bool connection_error;

    int howmany;
    int timeout;
};

#endif /* WIIMOTETHREAD_H_ */
