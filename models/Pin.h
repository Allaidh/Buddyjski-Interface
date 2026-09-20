#pragma once

#include <string>

#include "AltFunc.h"
#include "Type.h"

#define usi unsigned short int

enum class Pull
{
    None,
    Up,
    Down
};

enum class Level
{
    None,
    Low,
    High
};

enum class Direction
{
    None,
    Input,
    Output
};

class Pin
{
private:
    usi id;
    usi bcm;
    std::string name;
    bool isProgrammable;
    Type type;
    AltFunc* funkcjeAlt;
    Pull pull;
    Level value;
    Direction state;

public:
    Pin(); 
    Pin(usi id, usi bcm, std::string name, Type type, Pull pull, Level value, Direction state);
    ~Pin();

    static AltFunc* getAltFunctions(unsigned short id);
};
