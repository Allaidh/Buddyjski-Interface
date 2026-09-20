#include "Pin.h"
Pin::Pin(){

    funkcjeAlt = nullptr;
}
Pin::Pin(usi id, usi bcm, std::string name, Type type, Pull pull, Level value, Direction state)
    : id(id),
      bcm(bcm),
      name(name),
    isProgrammable(type == Type::GPIO),
      type(type),
    funkcjeAlt(type == Type::GPIO ? getAltFunctions(id) : nullptr),
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
    AltFunc* funkcjeAlt = new AltFunc[7];
        
        switch(id){
            case 3:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_SPI_RXD;
                funkcjeAlt[2] = AltFunc::R_UART1_RXD;
                funkcjeAlt[3] = AltFunc::R_PWM7;
                funkcjeAlt[4] = AltFunc::I2C4_SDA;
                break;
                
            case 5:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_SPI_TXD;
                funkcjeAlt[2] = AltFunc::R_UART1_TXD;
                funkcjeAlt[3] = AltFunc::R_PWM6;
                funkcjeAlt[4] = AltFunc::I2C4_SCL;
                break;
                
            case 7:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::UART5_TXD;
                funkcjeAlt[2] = AltFunc::DCLK_SPI_LCD;
                funkcjeAlt[3] = AltFunc::AP_I2C2_SCL;
                funkcjeAlt[4] = AltFunc::PRI_TDI;
                break;
                
            case 8:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_UART0_TXD;
                funkcjeAlt[2] = AltFunc::R_CAN_TX0;
                funkcjeAlt[3] = AltFunc::R_PWM8;
                funkcjeAlt[4] = AltFunc::AP_I2C3_SCL;
                funkcjeAlt[5] = AltFunc::ONE_WIRE;
                break;
                
            case 10:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_UART0_TXD;
                funkcjeAlt[2] = AltFunc::R_CAN_TX0;
                funkcjeAlt[3] = AltFunc::R_IR_RX;
                funkcjeAlt[4] = AltFunc::AP_I2C3_SDA;
                funkcjeAlt[5] = AltFunc::KP_MKOUT_2;
                break;
                
            case 11:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::UART5_RXD;
                funkcjeAlt[2] = AltFunc::DCX_DOUT1_SPI_LCD;
                funkcjeAlt[3] = AltFunc::AP_I2C2_SDA;
                funkcjeAlt[4] = AltFunc::PRI_TMS;
                break;
                
            case 12:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::PWM9;
                funkcjeAlt[2] = AltFunc::CS_SPI_LCD;
                funkcjeAlt[3] = AltFunc::PCIe2_WAKEN;
                break;
                
            case 13:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::UART5_CTS_N;
                funkcjeAlt[2] = AltFunc::DIN_SPI_LCD;
                funkcjeAlt[3] = AltFunc::UART9_TXD;
                funkcjeAlt[4] = AltFunc::PRI_TCK;
                break;
                
            case 15:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::UART5_RTS_N;
                funkcjeAlt[2] = AltFunc::DOUT0_SPI_LCD;
                funkcjeAlt[3] = AltFunc::UART9_RXD;
                funkcjeAlt[4] = AltFunc::PRI_TDO;
                break;
                
            case 16:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::MN_CLK2;
                funkcjeAlt[2] = AltFunc::VCXO_OUT;
                funkcjeAlt[3] = AltFunc::DSI_TE;
                funkcjeAlt[4] = AltFunc::R_I2C0_SCL;
                break;
                
            case 18:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::MN_CLK;
                funkcjeAlt[2] = AltFunc::PWM7;
                funkcjeAlt[3] = AltFunc::R_I2C0_SDA;
                break;
                
            case 19:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI2_TXD;
                funkcjeAlt[2] = AltFunc::SPI3_TXD;
                funkcjeAlt[3] = AltFunc::AP_I2C3_SCL;
                funkcjeAlt[4] = AltFunc::UART8_CTSN;
                funkcjeAlt[5] = AltFunc::R_PWM0;
                funkcjeAlt[6] = AltFunc::KP_MKOUT_2;
                break;
                
            case 21:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI2_RXD;
                funkcjeAlt[2] = AltFunc::SPI3_RXD;
                funkcjeAlt[3] = AltFunc::AP_I2C3_SDA;
                funkcjeAlt[4] = AltFunc::UART8_RTS_N;
                funkcjeAlt[5] = AltFunc::R_PWM1;
                funkcjeAlt[6] = AltFunc::KP_MKIN_3;
                break;
                
            case 22:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_SPI_SCLK;
                funkcjeAlt[2] = AltFunc::R_UART1_CTS_N;
                funkcjeAlt[3] = AltFunc::R_PWM4;
                funkcjeAlt[4] = AltFunc::R_I2C0_SCL;
                funkcjeAlt[5] = AltFunc::KP_MKIN_3;
                break;
                
            case 23:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI2_SCLK;
                funkcjeAlt[2] = AltFunc::SPI3_SCLK;
                funkcjeAlt[3] = AltFunc::CAN_TX0;
                funkcjeAlt[4] = AltFunc::UART8_TXD;
                funkcjeAlt[5] = AltFunc::AP_I2C4_SCL;
                break;
                
            case 24:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::SPI2_FRM;
                funkcjeAlt[2] = AltFunc::SPI3_FRM;
                funkcjeAlt[3] = AltFunc::CAN_RX0;
                funkcjeAlt[4] = AltFunc::UART8_RXD;
                funkcjeAlt[5] = AltFunc::AP_I2C4_SDA;
                break;
                
            case 26:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::R_SPI_FRM;
                funkcjeAlt[2] = AltFunc::R_UART1_RTS_N;
                funkcjeAlt[3] = AltFunc::R_PWM5;
                funkcjeAlt[4] = AltFunc::R_I2C0_SDA;
                funkcjeAlt[5] = AltFunc::KP_MKOUT_3;
                break;
                
            case 27:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_TX_D3;
                funkcjeAlt[2] = AltFunc::I2C3_SDA;
                funkcjeAlt[3] = AltFunc::R_I2S3_LRCK;
                funkcjeAlt[4] = AltFunc::PWM9;
                break;
                
            case 28:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_TX_D2;
                funkcjeAlt[2] = AltFunc::I2C3_SCL;
                funkcjeAlt[3] = AltFunc::R_I2S3_SCLK;
                funkcjeAlt[4] = AltFunc::PWM8;
                break;
                
            case 29:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RXDV;
                funkcjeAlt[2] = AltFunc::UART1_TXD;
                funkcjeAlt[3] = AltFunc::PWM1;
                funkcjeAlt[4] = AltFunc::PCIe0_PERSTN;
                break;
                
            case 31:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RX_D0;
                funkcjeAlt[2] = AltFunc::UART1_RXD;
                funkcjeAlt[3] = AltFunc::PWM2;
                funkcjeAlt[4] = AltFunc::PCIe0_WAKEN;
                break;
                
            case 32:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RX_D3;
                funkcjeAlt[2] = AltFunc::UART4_RXD;
                funkcjeAlt[3] = AltFunc::PWM4;
                funkcjeAlt[4] = AltFunc::PCIe1_CLKREQN;
                break;
                
            case 33:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RX_D1;
                funkcjeAlt[2] = AltFunc::UART1_CTS_N;
                funkcjeAlt[3] = AltFunc::_32K_OUT;
                funkcjeAlt[4] = AltFunc::PCIe0_CLKREQN;
                break;
                
            case 35:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RX_CLK;
                funkcjeAlt[2] = AltFunc::UART1_RTS_N;
                funkcjeAlt[3] = AltFunc::PCIe1_PERSTN;
                break;
                
            case 36:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_TX_D0;
                funkcjeAlt[2] = AltFunc::UART4_CTS_N;
                funkcjeAlt[3] = AltFunc::PWM5;
                funkcjeAlt[4] = AltFunc::PCIe2_PERSTN;
                break;
                
            case 37:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_RX_D2;
                funkcjeAlt[2] = AltFunc::UART4_TXD;
                funkcjeAlt[3] = AltFunc::PWM3;
                funkcjeAlt[4] = AltFunc::PCIe1_WAKEN;
                break;
                
            case 38:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_CLK_REF;
                funkcjeAlt[2] = AltFunc::PWM16;
                break;
                
            case 40:
                funkcjeAlt[0] = AltFunc::GPIO;
                funkcjeAlt[1] = AltFunc::GMAC1_TX;
                funkcjeAlt[2] = AltFunc::PWM7;
                funkcjeAlt[3] = AltFunc::PCIe2_CLKREQN;
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
void Pin::setPull(Pull _pull)
{
    pull = _pull;
}
void Pin::setValue(Level _level)
{
    value = _level;
}
void Pin::setDirection(Direction _state)
{
    state = _state;
}