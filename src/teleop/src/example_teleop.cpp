#include <iostream>
#include <string>
#include "teleop.h"

typedef std::string String;

int main(){
    Teleop joystick;
    int check = joystick.connect();
    if (check == -1) return -1;
    
    while (true)
    {
        if(joystick.isEvent())
        {
            joystick.printEvent();
        }
    }
    
    return 0;
}