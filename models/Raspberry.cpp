#include "Pin.h"
#include <iostream>
class Raspberry
{
private:
    Pin pins[40];
    std::string name;
    
public:
    Raspberry(std::string name)
    {
        this->name = name;
        for(size_t i = 0; i < 40; i++)
        {
            // pins[i] = 
        }
    }
};
