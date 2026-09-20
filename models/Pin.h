#pragma once

#include <string>

#include "AltFunc.h"
#include "Type.h"
using usi = unsigned short int;

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
    Pin(const Pin& other);
    Pin& operator=(const Pin& other);
    Pin(usi id, usi bcm, std::string name, Type type, Pull pull, Level value, Direction state);
    ~Pin();

    static AltFunc* getAltFunctions(unsigned short id);


    usi getId() const;
    usi getBcm() const;
    std::string getName() const;
    bool getIsProgrammable() const;
    Type getType() const;
    Pull getPull() const;
    Level getValue() const;
    Direction getDirection() const;
};
