#include "Raspberry.h"

std::string altFuncToString(AltFunc func)
{
    switch(func)
    {
        case AltFunc::NONE:               return "NONE";
        case AltFunc::GPIO:               return "GPIO";
        case AltFunc::I2C4_SDA:           return "I2C4_SDA";
        case AltFunc::I2C4_SCL:           return "I2C4_SCL";
        case AltFunc::AP_I2C2_SCL:        return "AP_I2C2_SCL";
        case AltFunc::AP_I2C2_SDA:        return "AP_I2C2_SDA";
        case AltFunc::AP_I2C3_SCL:        return "AP_I2C3_SCL";
        case AltFunc::AP_I2C3_SDA:        return "AP_I2C3_SDA";
        case AltFunc::AP_I2C4_SCL:        return "AP_I2C4_SCL";
        case AltFunc::AP_I2C4_SDA:        return "AP_I2C4_SDA";
        case AltFunc::R_I2C0_SCL:         return "R_I2C0_SCL";
        case AltFunc::R_I2C0_SDA:         return "R_I2C0_SDA";
        case AltFunc::I2C3_SCL:           return "I2C3_SCL";
        case AltFunc::I2C3_SDA:           return "I2C3_SDA";
        case AltFunc::UART1_TXD:          return "UART1_TXD";
        case AltFunc::UART1_RXD:          return "UART1_RXD";
        case AltFunc::UART1_CTS_N:        return "UART1_CTS_N";
        case AltFunc::UART1_RTS_N:        return "UART1_RTS_N";
        case AltFunc::UART4_TXD:          return "UART4_TXD";
        case AltFunc::UART4_RXD:          return "UART4_RXD";
        case AltFunc::UART4_CTS_N:        return "UART4_CTS_N";
        case AltFunc::UART5_TXD:          return "UART5_TXD";
        case AltFunc::UART5_RXD:          return "UART5_RXD";
        case AltFunc::UART5_CTS_N:        return "UART5_CTS_N";
        case AltFunc::UART5_RTS_N:        return "UART5_RTS_N";
        case AltFunc::UART8_TXD:          return "UART8_TXD";
        case AltFunc::UART8_RXD:          return "UART8_RXD";
        case AltFunc::UART8_CTSN:         return "UART8_CTSN";
        case AltFunc::UART8_RTS_N:        return "UART8_RTS_N";
        case AltFunc::UART9_TXD:          return "UART9_TXD";
        case AltFunc::UART9_RXD:          return "UART9_RXD";
        case AltFunc::R_UART0_TXD:        return "R_UART0_TXD";
        case AltFunc::R_UART1_RXD:        return "R_UART1_RXD";
        case AltFunc::R_UART1_TXD:        return "R_UART1_TXD";
        case AltFunc::R_UART1_CTS_N:      return "R_UART1_CTS_N";
        case AltFunc::R_UART1_RTS_N:      return "R_UART1_RTS_N";
        case AltFunc::R_SPI_RXD:          return "R_SPI_RXD";
        case AltFunc::R_SPI_TXD:          return "R_SPI_TXD";
        case AltFunc::R_SPI_SCLK:         return "R_SPI_SCLK";
        case AltFunc::R_SPI_FRM:          return "R_SPI_FRM";
        case AltFunc::SPI2_TXD:           return "SPI2_TXD";
        case AltFunc::SPI2_RXD:           return "SPI2_RXD";
        case AltFunc::SPI2_SCLK:          return "SPI2_SCLK";
        case AltFunc::SPI2_FRM:           return "SPI2_FRM";
        case AltFunc::SPI3_TXD:           return "SPI3_TXD";
        case AltFunc::SPI3_RXD:           return "SPI3_RXD";
        case AltFunc::SPI3_SCLK:          return "SPI3_SCLK";
        case AltFunc::SPI3_FRM:           return "SPI3_FRM";
        case AltFunc::DCLK_SPI_LCD:       return "DCLK_SPI_LCD";
        case AltFunc::DCX_DOUT1_SPI_LCD:  return "DCX_DOUT1_SPI";
        case AltFunc::DIN_SPI_LCD:        return "DIN_SPI_LCD";
        case AltFunc::DOUT0_SPI_LCD:      return "DOUT0_SPI_LCD";
        case AltFunc::CS_SPI_LCD:         return "CS_SPI_LCD";
        case AltFunc::PWM1:               return "PWM1";
        case AltFunc::PWM2:               return "PWM2";
        case AltFunc::PWM3:               return "PWM3";
        case AltFunc::PWM4:               return "PWM4";
        case AltFunc::PWM5:               return "PWM5";
        case AltFunc::PWM7:               return "PWM7";
        case AltFunc::PWM8:               return "PWM8";
        case AltFunc::PWM9:               return "PWM9";
        case AltFunc::PWM16:              return "PWM16";
        case AltFunc::R_PWM0:             return "R_PWM0";
        case AltFunc::R_PWM1:             return "R_PWM1";
        case AltFunc::R_PWM4:             return "R_PWM4";
        case AltFunc::R_PWM5:             return "R_PWM5";
        case AltFunc::R_PWM6:             return "R_PWM6";
        case AltFunc::R_PWM7:             return "R_PWM7";
        case AltFunc::R_PWM8:             return "R_PWM8";
        case AltFunc::CAN_TX0:            return "CAN_TX0";
        case AltFunc::CAN_RX0:            return "CAN_RX0";
        case AltFunc::R_CAN_TX0:          return "R_CAN_TX0";
        case AltFunc::R_I2S3_LRCK:        return "R_I2S3_LRCK";
        case AltFunc::R_I2S3_SCLK:        return "R_I2S3_SCLK";
        case AltFunc::GMAC1_TX:           return "GMAC1_TX";
        case AltFunc::GMAC1_TX_D0:        return "GMAC1_TX_D0";
        case AltFunc::GMAC1_TX_D2:        return "GMAC1_TX_D2";
        case AltFunc::GMAC1_TX_D3:        return "GMAC1_TX_D3";
        case AltFunc::GMAC1_RX_D0:        return "GMAC1_RX_D0";
        case AltFunc::GMAC1_RX_D1:        return "GMAC1_RX_D1";
        case AltFunc::GMAC1_RX_D2:        return "GMAC1_RX_D2";
        case AltFunc::GMAC1_RX_D3:        return "GMAC1_RX_D3";
        case AltFunc::GMAC1_RXDV:         return "GMAC1_RXDV";
        case AltFunc::GMAC1_RX_CLK:       return "GMAC1_RX_CLK";
        case AltFunc::GMAC1_CLK_REF:      return "GMAC1_CLK_REF";
        case AltFunc::PCIe0_PERSTN:       return "PCIe0_PERSTN";
        case AltFunc::PCIe0_WAKEN:        return "PCIe0_WAKEN";
        case AltFunc::PCIe0_CLKREQN:      return "PCIe0_CLKREQN";
        case AltFunc::PCIe1_PERSTN:       return "PCIe1_PERSTN";
        case AltFunc::PCIe1_WAKEN:        return "PCIe1_WAKEN";
        case AltFunc::PCIe1_CLKREQN:      return "PCIe1_CLKREQN";
        case AltFunc::PCIe2_PERSTN:       return "PCIe2_PERSTN";
        case AltFunc::PCIe2_WAKEN:        return "PCIe2_WAKEN";
        case AltFunc::PCIe2_CLKREQN:      return "PCIe2_CLKREQN";
        case AltFunc::PRI_TDI:            return "PRI_TDI";
        case AltFunc::PRI_TMS:            return "PRI_TMS";
        case AltFunc::PRI_TCK:            return "PRI_TCK";
        case AltFunc::PRI_TDO:            return "PRI_TDO";
        case AltFunc::MN_CLK:             return "MN_CLK";
        case AltFunc::MN_CLK2:            return "MN_CLK2";
        case AltFunc::VCXO_OUT:           return "VCXO_OUT";
        case AltFunc::DSI_TE:             return "DSI_TE";
        case AltFunc::_32K_OUT:           return "32K_OUT";
        case AltFunc::R_IR_RX:            return "R_IR_RX";
        case AltFunc::ONE_WIRE:           return "ONE_WIRE";
        case AltFunc::KP_MKOUT_2:         return "KP_MKOUT_2";
        case AltFunc::KP_MKOUT_3:         return "KP_MKOUT_3";
        case AltFunc::KP_MKIN_3:          return "KP_MKIN_3";
        default:                          return "UNKNOWN";
    }
}

Raspberry::Raspberry(std::string name)
{
    this->name = name;

    std::ifstream file("pins.txt");

    if (!file.is_open())
    {
        UI::showError("Nie mozna otworzyc pliku pins.txt");
        return;
    }

    std::string line;

    for (size_t i = 0; i < 40; i++)
    {
        if (!std::getline(file, line))
        {
            UI::showError("Plik zawiera mniej niz 40 wierszy!");
            break;
        }

        std::stringstream ss(line);

        std::string id, bcm, pinName, type, pull, value, direction;

        std::getline(ss, id, '\t');
        std::getline(ss, bcm, '\t');
        std::getline(ss, pinName, '\t');
        std::getline(ss, type, '\t');
        std::getline(ss, pull, '\t');
        std::getline(ss, value, '\t');
        std::getline(ss, direction, '\t');

        usi pinId = std::stoi(id);
        usi pinBcm = 0;

        if (bcm != "null")
            pinBcm = std::stoi(bcm);

        pins[i] = Pin(
            pinId, pinBcm, pinName,
            parseType(type), parsePull(pull),
            parseLevel(value), parseDirection(direction)
        );
    }

    file.close();
}

Pull Raspberry::parsePull(std::string text)
{
    if (text == "up")   return Pull::Up;
    if (text == "down") return Pull::Down;
    return Pull::None;
}

Level Raspberry::parseLevel(std::string text)
{
    if (text == "low")  return Level::Low;
    if (text == "high") return Level::High;
    return Level::None;
}

Direction Raspberry::parseDirection(std::string text)
{
    if (text == "input")  return Direction::Input;
    if (text == "output") return Direction::Output;
    return Direction::None;
}

Type Raspberry::parseType(std::string text)
{
    if (text == "Ground")  return Type::Ground;
    if (text == "VCC_3V3") return Type::VCC_3V3;
    if (text == "VCC_5V")  return Type::VCC_5V;
    return Type::GPIO;
}

void Raspberry::displayPins()
{
    auto printMode = [&](Direction dir) {
        if (dir == Direction::Input)       std::cout << UI::CYAN   << " INPUT" << UI::RESET;
        else if (dir == Direction::Output) std::cout << UI::YELLOW << "OUTPUT" << UI::RESET;
        else                               std::cout << UI::GRAY   << "  --  " << UI::RESET;
    };

    auto printLevel = [&](Level lvl) {
        if (lvl == Level::High)      std::cout << UI::GREEN << " HIGH " << UI::RESET;
        else if (lvl == Level::Low)  std::cout << UI::RED   << " LOW  " << UI::RESET;
        else                         std::cout << UI::GRAY  << "  --  " << UI::RESET;
    };

    auto printPull = [&](Pull pull) {
        if (pull == Pull::Up)         std::cout << UI::BLUE    << "  UP  " << UI::RESET;
        else if (pull == Pull::Down)  std::cout << UI::MAGENTA << " DOWN " << UI::RESET;
        else                          std::cout << UI::GRAY    << "  --  " << UI::RESET;
    };

    auto printBcm = [&](int bcm) {
        if (bcm <= 0) std::cout << UI::GRAY << " -- " << UI::RESET;
        else          std::cout << " " << std::setw(2) << std::setfill(' ') << bcm << " ";
    };

    auto printPinName = [&](const Pin& pin, bool leftAlign) {
        std::string displayName;
        bool isAltActive = false;

        if (pin.getType() == Type::GPIO) 
        {
            AltFunc current = pin.getCurrentFunc();
            if (current != AltFunc::GPIO && current != AltFunc::NONE)
            {
                displayName = altFuncToString(current);
                isAltActive = true;
            }
            else 
                displayName = pin.getName();
        }
        else 
            displayName = pin.getName();

        if (displayName.length() > 16) 
            displayName = displayName.substr(0, 13) + "...";

        int pad = 16 - displayName.length();
        std::string padded = leftAlign ? (displayName + std::string(pad, ' ')) 
                                       : (std::string(pad, ' ') + displayName);

        if (isAltActive)
            std::cout << UI::BG_ALT << padded << UI::RESET;
        else
        {
            switch (pin.getType())
            {
                case Type::VCC_5V:   std::cout << UI::BG_5V << padded << UI::RESET; break;
                case Type::VCC_3V3:  std::cout << UI::BG_3V3 << padded << UI::RESET; break;
                case Type::Ground:   std::cout << UI::BG_GND << padded << UI::RESET; break;
                case Type::GPIO:     std::cout << UI::GREEN << padded << UI::RESET; break;
                default:             std::cout << UI::GRAY << padded << UI::RESET; break;
            }
        }
    };

    std::cout << "\n" << UI::BOLD << UI::CYAN;
    std::cout << " +" << std::string(94, '=') << "+\n";
    
    std::string title = name + " - PHYSICAL PINOUT MAP";
    int titlePad = (94 - title.length()) / 2;
    std::cout << " |" << std::string(titlePad, ' ') << title 
              << std::string(94 - titlePad - title.length(), ' ') << "|\n";
    std::cout << " +" << std::string(94, '=') << "+\n" << UI::RESET;

    const std::string TOP = " +------+------+------+----+----------------+----+----+----------------+----+------+------+------+\n";
    const std::string MID = " +------+------+------+----+----------------+----+----+----------------+----+------+------+------+\n";

    std::cout << TOP;
    std::cout << " | MODE | LVL  | PULL |BCM |  ACTIVE  ROLE  | ID | ID |  ACTIVE  ROLE  |BCM | PULL | LVL  | MODE |\n";
    std::cout << MID;

    for (int r = 0; r < 20; r++)
    {
        Pin& leftPin  = pins[2 * r];
        Pin& rightPin = pins[2 * r + 1];

        std::cout << " |"; printMode(leftPin.getDirection());
        std::cout << "|";  printLevel(leftPin.getValue());
        std::cout << "|";  printPull(leftPin.getPull());
        std::cout << "|";  printBcm(leftPin.getBcm());
        std::cout << "|";  printPinName(leftPin, false);
        std::cout << "|" << UI::BOLD << " " << std::setw(2) << std::setfill('0') << leftPin.getId() << " " << UI::RESET;
        std::cout << "|" << UI::BOLD << " " << std::setw(2) << std::setfill('0') << rightPin.getId() << " " << UI::RESET;
        std::cout << "|"; printPinName(rightPin, true);
        std::cout << "|"; printBcm(rightPin.getBcm());
        std::cout << "|"; printPull(rightPin.getPull());
        std::cout << "|"; printLevel(rightPin.getValue());
        std::cout << "|"; printMode(rightPin.getDirection());
        std::cout << "|\n";
    }
    std::cout << MID;

    std::cout << "\n  Legenda: " 
              << UI::BG_5V << "  5V  " << UI::RESET << " Power   "
              << UI::BG_3V3 << " 3.3V " << UI::RESET << " Power   "
              << UI::BG_GND << " GND " << UI::RESET << " Ground   "
              << UI::GREEN << "* GPIO" << UI::RESET << " GPIO Mode   "
              << UI::BG_ALT << " ACTIVE ALT " << UI::RESET << " Active Alt\n";
}

void Raspberry::changePull()
{
    int pinId = UI::getValidatedPinId();
    if (pinId == -1) return;

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() + ") nie jest programowalny (VCC/GND).");
        return;
    }

    std::string current = (pin.getPull() == Pull::Up ? "PULL UP" : 
                          pin.getPull() == Pull::Down ? "PULL DOWN" : "NONE");
    UI::printPinCardHeader(pinId, pin.getName());
    UI::printPinCardRow("Aktualny pull", UI::CYAN, current);
    UI::printPinCardFooter();

    std::cout << "  " << UI::CYAN << "[1]" << UI::RESET << " PULL UP\n";
    std::cout << "  " << UI::CYAN << "[2]" << UI::RESET << " PULL DOWN\n";
    std::cout << "  " << UI::CYAN << "[3]" << UI::RESET << " NONE (brak)\n";

    int choice = UI::getValidatedChoice(1, 3);
    if (choice == -1) return;

    Pull newPull = (choice == 1 ? Pull::Up : choice == 2 ? Pull::Down : Pull::None);
    pin.setPull(newPull);

    std::string newStr = (newPull == Pull::Up ? "UP" : newPull == Pull::Down ? "DOWN" : "NONE");
    UI::showSuccess("Rezystor pull pinu " + std::to_string(pinId) + " ustawiono na: " + newStr);
}

void Raspberry::togglePin()
{
    int pinId = UI::getValidatedPinId();
    if (pinId == -1) return;

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() + ") nie jest programowalny.");
        return;
    }

    std::string current = (pin.getValue() == Level::High ? "HIGH (1)" : 
                          pin.getValue() == Level::Low ? "LOW (0)" : "NONE");
    std::string color = (pin.getValue() == Level::High ? UI::GREEN : UI::RED);

    UI::printPinCardHeader(pinId, pin.getName());
    UI::printPinCardRow("Aktualny stan", color, current);
    UI::printPinCardFooter();

    std::cout << "  " << UI::CYAN << "[1]" << UI::RESET << " Ustaw HIGH (1)\n";
    std::cout << "  " << UI::CYAN << "[2]" << UI::RESET << " Ustaw LOW (0)\n";

    int choice = UI::getValidatedChoice(1, 2);
    if (choice == -1) return;

    Level newLvl = (choice == 1 ? Level::High : Level::Low);
    pin.setValue(newLvl);

    UI::showSuccess("Stan logiczny pinu " + std::to_string(pinId) + " ustawiono na: " + 
                    (newLvl == Level::High ? "HIGH" : "LOW"));
}

void Raspberry::changePinMode()
{
    int pinId = UI::getValidatedPinId();
    if (pinId == -1) return;

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() + ") nie jest programowalny.");
        return;
    }

    std::string current = (pin.getDirection() == Direction::Input ? "INPUT (Wejscie)" : 
                          pin.getDirection() == Direction::Output ? "OUTPUT (Wyjscie)" : "NONE");

    UI::printPinCardHeader(pinId, pin.getName());
    UI::printPinCardRow("Aktualny tryb", UI::YELLOW, current);
    UI::printPinCardFooter();

    std::cout << "  " << UI::CYAN << "[1]" << UI::RESET << " INPUT  (Odbior sygnalu)\n";
    std::cout << "  " << UI::CYAN << "[2]" << UI::RESET << " OUTPUT (Wysylanie sygnalu)\n";

    int choice = UI::getValidatedChoice(1, 2);
    if (choice == -1) return;

    Direction newDir = (choice == 1 ? Direction::Input : Direction::Output);
    pin.setDirection(newDir);

    UI::showSuccess("Kierunek pinu " + std::to_string(pinId) + " ustawiono na: " + 
                    (newDir == Direction::Input ? "INPUT" : "OUTPUT"));
}

void Raspberry::selectAlternateFunction()
{
    int pinId = UI::getValidatedPinId();
    if (pinId == -1) return;

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() + ") nie jest programowalny.");
        return;
    }

    AltFunc* availableFunctions = Pin::getAltFunctions(pin.getId());
    if (availableFunctions == nullptr)
    {
        UI::showError("Ten pin nie posiada przypisanych funkcji alternatywnych.");
        return;
    }

    UI::printPinCardHeader(pinId, pin.getName());
    UI::printPinCardRow("Aktywna rola", UI::MAGENTA, altFuncToString(pin.getCurrentFunc()));
    UI::printPinCardFooter();

    std::cout << "  " << UI::BOLD << "Dostepne role dla tego pinu:" << UI::RESET << "\n";

    int availableCount = 0;
    for (int index = 0; index < 7 && availableFunctions[index] != AltFunc::NONE; ++index)
    {
        ++availableCount;
        std::cout << "  " << UI::CYAN << "[" << availableCount << "]" << UI::RESET 
                  << " " << UI::BOLD << altFuncToString(availableFunctions[index]) << UI::RESET << "\n";
    }

    int choice = UI::getValidatedChoice(1, availableCount);
    if (choice == -1)
    {
        delete[] availableFunctions;
        return;
    }

    AltFunc selectedFunction = availableFunctions[choice - 1];
    bool changed = pin.setAltFunc(selectedFunction);
    delete[] availableFunctions;

    if (changed)
        UI::showSuccess("Multiplekser pinu " + std::to_string(pinId) + " ustawiono na: " + altFuncToString(selectedFunction));
    else
        UI::showError("Nie udalo sie zmienic funkcji alternatywnej.");
}