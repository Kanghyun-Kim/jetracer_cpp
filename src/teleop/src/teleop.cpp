#include "teleop.h"
#include <fcntl.h>
#include "unistd.h"

int Teleop::connect()
{
    _fd = open("/dev/input/js0", O_RDONLY);
    if(_fd < 0)
    {
        std::cout << "Connection Failed, check /dev/input/js0\n";
        return -1;
    } 
    else
    {
        std::cout << "Connected\n";
        return 0;
    } 
}

bool Teleop::isEvent()
{
    int bytes = read(_fd, &(this->_event), sizeof(js_event));
    
    if(bytes==-1) return false;
    return bytes == sizeof(js_event);
}

void Teleop::printEvent()
{
    if(_event.type == JS_EVENT_BUTTON)
    {
        printf("Button %d : %d\n", _event.number, _event.value);
    }
    else if(_event.type == JS_EVENT_AXIS)
    {
        printf("Axis %d : %d\n", _event.number, _event.value);
    }
}

