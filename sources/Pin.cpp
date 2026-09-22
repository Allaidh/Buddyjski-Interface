#include "Pin.h"
Pin::Pin() : funkcjeAlt(nullptr), currentFunc(AltFunc::NONE) {}

Pin::Pin(usi id, usi bcm, std::string name, Type type, Pull pull, Level value, Direction state)
    : id(id),
      bcm(bcm),
      name(name),
      isProgrammable(type == Type::GPIO),
      type(type),
      funkcjeAlt(type == Type::GPIO ? getAltFunctions(id) : nullptr),
      currentFunc(type == Type::GPIO ? AltFunc::GPIO : AltFunc::NONE), 
      pull(pull),
      value(value),
      state(state)
{}


Pin::Pin(const Pin& other)
    : id(other.id),
      bcm(other.bcm),
      name(other.name),
      isProgrammable(other.isProgrammable),
      type(other.type),
      currentFunc(other.currentFunc),
      pull(other.pull),
      value(other.value),
      state(other.state)
{
    if (other.funkcjeAlt != nullptr) {
        funkcjeAlt = new AltFunc[7];
        for (int i = 0; i < 7; ++i) {
            funkcjeAlt[i] = other.funkcjeAlt[i];
        }
    } else {
        funkcjeAlt = nullptr;
    }
}

Pin& Pin::operator=(const Pin& other)
{
    if (this == &other)
        return *this;
    delete[] funkcjeAlt;
    funkcjeAlt = nullptr;
    id = other.id;
    bcm = other.bcm;
    name = other.name;
    isProgrammable = other.isProgrammable;
    type = other.type;
    currentFunc = other.currentFunc;
    pull = other.pull;
    value = other.value;
    state = other.state;
    if (other.funkcjeAlt != nullptr) {
        funkcjeAlt = new AltFunc[7];
        for (int i = 0; i < 7; ++i) {
            funkcjeAlt[i] = other.funkcjeAlt[i];
        }
    }

    return *this;
}






Pin::~Pin()
{
    if(funkcjeAlt != nullptr){
        delete[] funkcjeAlt;
        funkcjeAlt = nullptr;
    }
}

AltFunc* Pin::getAltFunctions(unsigned short id)
{
    AltFunc* funkcjeAlt = new AltFunc[7] {AltFunc::NONE };
        
        switch(id){
            case 3:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SDA1;
                funkcjeAlt[2] = AltFunc::SA3;
                funkcjeAlt[3] = AltFunc::LCD_VSYNC;
                funkcjeAlt[4] = AltFunc::SPI3_MOSI;
                funkcjeAlt[5] = AltFunc::CTS2;
                funkcjeAlt[6] = AltFunc::SDA3;
                break;

            case 5:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SCL1;
                funkcjeAlt[2] = AltFunc::SA2;
                funkcjeAlt[3] = AltFunc::LCD_HSYNC;
                funkcjeAlt[4] = AltFunc::SPI3_SCLK;
                funkcjeAlt[5] = AltFunc::RTS2;
                funkcjeAlt[6] = AltFunc::SCL3;
                break;

            case 7:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GPCLK0;
                funkcjeAlt[2] = AltFunc::SA1;
                funkcjeAlt[3] = AltFunc::DPI_D0;
                funkcjeAlt[4] = AltFunc::SPI4_CE0_N;
                funkcjeAlt[5] = AltFunc::TXD3;
                funkcjeAlt[6] = AltFunc::SDA3;
                break;

            case 8:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::TXD0;
                funkcjeAlt[2] = AltFunc::SD6;
                funkcjeAlt[3] = AltFunc::DPI_D10;
                funkcjeAlt[4] = AltFunc::SPI5_MOSI;
                funkcjeAlt[5] = AltFunc::CTS5;
                funkcjeAlt[6] = AltFunc::TXD1;
                break;

            case 10:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::RXD0;
                funkcjeAlt[2] = AltFunc::SD7;
                funkcjeAlt[3] = AltFunc::DPI_D11;
                funkcjeAlt[4] = AltFunc::SPI5_SCLK;
                funkcjeAlt[5] = AltFunc::RTS5;
                funkcjeAlt[6] = AltFunc::RXD1;
                break;

            case 11:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::FL1;
                funkcjeAlt[2] = AltFunc::SD9;
                funkcjeAlt[3] = AltFunc::DPI_D13;
                funkcjeAlt[4] = AltFunc::RTS0;
                funkcjeAlt[5] = AltFunc::SPI1_CE1_N;
                funkcjeAlt[6] = AltFunc::RTS1;
                break;

            case 12:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PCM_CLK;
                funkcjeAlt[2] = AltFunc::SD10;
                funkcjeAlt[3] = AltFunc::DPI_D14;
                funkcjeAlt[4] = AltFunc::SPI6_CE0_N;
                funkcjeAlt[5] = AltFunc::SPI1_CE0_N;
                funkcjeAlt[6] = AltFunc::PWM0;
                break;

            case 13:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_DAT3;
                funkcjeAlt[2] = AltFunc::TE1;
                funkcjeAlt[3] = AltFunc::DPI_D23;
                funkcjeAlt[4] = AltFunc::SD1_DAT3;
                funkcjeAlt[5] = AltFunc::ARM_TMS;
                funkcjeAlt[6] = AltFunc::SPI6_CE1_N;
                break;

            case 15:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_CLK;
                funkcjeAlt[2] = AltFunc::SD14;
                funkcjeAlt[3] = AltFunc::DPI_D18;
                funkcjeAlt[4] = AltFunc::SD1_CLK;
                funkcjeAlt[5] = AltFunc::ARM_TRST;
                funkcjeAlt[6] = AltFunc::SDA6;
                break;

            case 16:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_CMD;
                funkcjeAlt[2] = AltFunc::SD15;
                funkcjeAlt[3] = AltFunc::DPI_D19;
                funkcjeAlt[4] = AltFunc::SD1_CMD;
                funkcjeAlt[5] = AltFunc::ARM_RTCK;
                funkcjeAlt[6] = AltFunc::SCL6;
                break;

            case 18:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_DAT0;
                funkcjeAlt[2] = AltFunc::SD16;
                funkcjeAlt[3] = AltFunc::DPI_D20;
                funkcjeAlt[4] = AltFunc::SD1_DAT0;
                funkcjeAlt[5] = AltFunc::ARM_TDO;
                funkcjeAlt[6] = AltFunc::SPI3_CE1_N;
                break;

            case 19:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI0_MOSI;
                funkcjeAlt[2] = AltFunc::SD2;
                funkcjeAlt[3] = AltFunc::DPI_D6;
                funkcjeAlt[4] = AltFunc::I2CSL_SDA;
                funkcjeAlt[5] = AltFunc::CTS4;
                funkcjeAlt[6] = AltFunc::SDA5;
                break;

            case 21:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI0_MISO;
                funkcjeAlt[2] = AltFunc::SD1;
                funkcjeAlt[3] = AltFunc::DPI_D5;
                funkcjeAlt[4] = AltFunc::I2CSL_SDI;
                funkcjeAlt[5] = AltFunc::RXD4;
                funkcjeAlt[6] = AltFunc::SCL4;
                break;

            case 22:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_DAT1;
                funkcjeAlt[2] = AltFunc::SD17;
                funkcjeAlt[3] = AltFunc::DPI_D21;
                funkcjeAlt[4] = AltFunc::SD1_DAT1;
                funkcjeAlt[5] = AltFunc::ARM_TCK;
                funkcjeAlt[6] = AltFunc::SPI4_CE1_N;
                break;

            case 23:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI0_SCLK;
                funkcjeAlt[2] = AltFunc::SD3;
                funkcjeAlt[3] = AltFunc::DPI_D7;
                funkcjeAlt[4] = AltFunc::I2CSL_SCL;
                funkcjeAlt[5] = AltFunc::RTS4;
                funkcjeAlt[6] = AltFunc::SCL5;
                break;

            case 24:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI0_CE0_N;
                funkcjeAlt[2] = AltFunc::SD0;
                funkcjeAlt[3] = AltFunc::DPI_D4;
                funkcjeAlt[4] = AltFunc::I2CSL_CE_N;
                funkcjeAlt[5] = AltFunc::TXD4;
                funkcjeAlt[6] = AltFunc::SDA4;
                break;

            case 26:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI0_CE1_N;
                funkcjeAlt[2] = AltFunc::SWE_N;
                funkcjeAlt[3] = AltFunc::DPI_D3;
                funkcjeAlt[4] = AltFunc::SPI4_SCLK;
                funkcjeAlt[5] = AltFunc::RTS3;
                funkcjeAlt[6] = AltFunc::SCL4;
                break;

            case 27:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SDA0;
                funkcjeAlt[2] = AltFunc::SA5;
                funkcjeAlt[3] = AltFunc::PCLK;
                funkcjeAlt[4] = AltFunc::SPI3_CE0_N;
                funkcjeAlt[5] = AltFunc::TXD2;
                funkcjeAlt[6] = AltFunc::SDA6;
                break;

            case 28:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SCL0;
                funkcjeAlt[2] = AltFunc::SA4;
                funkcjeAlt[3] = AltFunc::DE;
                funkcjeAlt[4] = AltFunc::SPI3_MISO;
                funkcjeAlt[5] = AltFunc::RXD2;
                funkcjeAlt[6] = AltFunc::SCL6;
                break;

            case 29:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GPCLK1;
                funkcjeAlt[2] = AltFunc::SA0;
                funkcjeAlt[3] = AltFunc::DPI_D1;
                funkcjeAlt[4] = AltFunc::SPI4_MISO;
                funkcjeAlt[5] = AltFunc::RXD3;
                funkcjeAlt[6] = AltFunc::SCL3;
                break;

            case 31:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GPCLK2;
                funkcjeAlt[2] = AltFunc::SOE_N;
                funkcjeAlt[3] = AltFunc::DPI_D2;
                funkcjeAlt[4] = AltFunc::SPI4_MOSI;
                funkcjeAlt[5] = AltFunc::CTS3;
                funkcjeAlt[6] = AltFunc::SDA4;
                break;

            case 32:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PWM0;
                funkcjeAlt[2] = AltFunc::SD4;
                funkcjeAlt[3] = AltFunc::DPI_D8;
                funkcjeAlt[4] = AltFunc::SPI5_CE0_N;
                funkcjeAlt[5] = AltFunc::TXD5;
                funkcjeAlt[6] = AltFunc::SDA5;
                break;

            case 33:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PWM1;
                funkcjeAlt[2] = AltFunc::SD5;
                funkcjeAlt[3] = AltFunc::DPI_D9;
                funkcjeAlt[4] = AltFunc::SPI5_MISO;
                funkcjeAlt[5] = AltFunc::RXD5;
                funkcjeAlt[6] = AltFunc::SCL5;
                break;

            case 35:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PCM_FS;
                funkcjeAlt[2] = AltFunc::SD11;
                funkcjeAlt[3] = AltFunc::DPI_D15;
                funkcjeAlt[4] = AltFunc::SPI6_MISO;
                funkcjeAlt[5] = AltFunc::SPI1_MISO;
                funkcjeAlt[6] = AltFunc::PWM1;
                break;

            case 36:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::FL0;
                funkcjeAlt[2] = AltFunc::SD8;
                funkcjeAlt[3] = AltFunc::DPI_D12;
                funkcjeAlt[4] = AltFunc::CTS0;
                funkcjeAlt[5] = AltFunc::SPI1_CE2_N;
                funkcjeAlt[6] = AltFunc::CTS1;
                break;

            case 37:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SD0_DAT2;
                funkcjeAlt[2] = AltFunc::TE0;
                funkcjeAlt[3] = AltFunc::DPI_D22;
                funkcjeAlt[4] = AltFunc::SD1_DAT2;
                funkcjeAlt[5] = AltFunc::ARM_TDI;
                funkcjeAlt[6] = AltFunc::SPI5_CE1_N;
                break;

            case 38:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PCM_DIN;
                funkcjeAlt[2] = AltFunc::SD12;
                funkcjeAlt[3] = AltFunc::DPI_D16;
                funkcjeAlt[4] = AltFunc::SPI6_MOSI;
                funkcjeAlt[5] = AltFunc::SPI1_MOSI;
                funkcjeAlt[6] = AltFunc::GPCLK0;
                break;

            case 40:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PCM_DOUT;
                funkcjeAlt[2] = AltFunc::SD13;
                funkcjeAlt[3] = AltFunc::DPI_D17;
                funkcjeAlt[4] = AltFunc::SPI6_SCLK;
                funkcjeAlt[5] = AltFunc::SPI1_SCLK;
                funkcjeAlt[6] = AltFunc::GPCLK1;
                break;

            default:
                delete[] funkcjeAlt;
                return nullptr;
        }
        
    return funkcjeAlt;
}
usi Pin::getId() const
{
    return id;
}

usi Pin::getBcm() const
{
    return bcm;
}

std::string Pin::getName() const
{
    return name;
}

bool Pin::getIsProgrammable() const
{
    return isProgrammable;
}

Type Pin::getType() const
{
    return type;
}

Pull Pin::getPull() const
{
    return pull;
}

Level Pin::getValue() const
{
    return value;
}

Direction Pin::getDirection() const
{
    return state;
}

void Pin::applyPullDefault()
{
    if (currentFunc != AltFunc::GPIO || state != Direction::Input)
        return;

    if (pull == Pull::Up)
        value = Level::High;
    else if (pull == Pull::Down)
        value = Level::Low;
    else
        value = Level::None;
}

void Pin::setPull(Pull _pull)
{
    pull = _pull;
    applyPullDefault();
}
void Pin::setValue(Level _level)
{
    value = _level;
}
void Pin::setDirection(Direction _state)
{
    state = _state;
    applyPullDefault();
}


AltFunc Pin::getCurrentFunc() const
{
    return currentFunc;
}

bool Pin::setAltFunc(AltFunc newFunc)
{
    if (!isProgrammable || funkcjeAlt == nullptr) {
        return false; 
    }
    for (int i = 0; i < 7; i++)
    {
        if (funkcjeAlt[i] == newFunc)
        {
            currentFunc = newFunc;
            if (newFunc != AltFunc::GPIO) {
                state = Direction::None; 
            } else {
                state = Direction::Input; 
                applyPullDefault();
            }

            return true; 
        }
    }
    return false; 
}
