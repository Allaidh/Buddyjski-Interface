#include <string>
#include "Type.h"

#define usi unsigned short int;

class Pin
{
private:
    usi Id; 
    std::string Name;
    bool isProgrammable;
    Type type;
    AltFunc* funkcjeAlt[6];
    

public:
    Pin(Type type){
        this -> type = type;
        funkcjeAlt = nullptr;
        if(type == Type.BCM){
            isProgrammable = true;
        }
        else{
            isProgrammable = false;
        }
    }

    static AltFuncs getAltFunctions(unsigned short id){
        switch(id){
            case 3:
                funkcjeAlt = new AltFunc{
                    AltFunc.GPIO,
                    AltFunc.R_SPI_RXD,
                    AltFunc.R_UART1_RXD,
                    AltFunc.R_PWM7,
                    AltFunc.I2C4_SDA
                };
        }
    }
};