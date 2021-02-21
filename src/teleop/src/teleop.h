#ifndef TELEOP_H
#define TELEOP_H

#include <iostream>

struct js_event {
    unsigned int time;      /* event timestamp in milliseconds */
    short value;   /* value */
    unsigned char type;     /* event type */
    unsigned char number;   /* axis/button number */
};

#define JS_EVENT_BUTTON 0x01 // button pressed/released
#define JS_EVENT_AXIS   0x02 // joystick moved
#define JS_EVENT_INIT   0x80 // initial state of device


class Teleop
{
private:
    int _fd;
    js_event _event;

public:
    Teleop(){}
    
    int connect();
    bool isEvent();
    void printEvent();
};

#endif //TELEOP_H