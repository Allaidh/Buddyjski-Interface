#include "../models/Raspberry.h"

std::string altFuncToString(AltFunc func)
{
    switch(func)
    {
        case AltFunc::NONE:          return "NONE";
        case AltFunc::GPIO:          return "GPIO";
        case AltFunc::SDA0:          return "SDA0";
        case AltFunc::SCL0:          return "SCL0";
        case AltFunc::SDA1:          return "SDA1";
        case AltFunc::SCL1:          return "SCL1";
        case AltFunc::SDA3:          return "SDA3";
        case AltFunc::SCL3:          return "SCL3";
        case AltFunc::SDA4:          return "SDA4";
        case AltFunc::SCL4:          return "SCL4";
        case AltFunc::SDA5:          return "SDA5";
        case AltFunc::SCL5:          return "SCL5";
        case AltFunc::SDA6:          return "SDA6";
        case AltFunc::SCL6:          return "SCL6";
        case AltFunc::SPI0_CE0_N:    return "SPI0_CE0_N";
        case AltFunc::SPI0_CE1_N:    return "SPI0_CE1_N";
        case AltFunc::SPI0_MISO:     return "SPI0_MISO";
        case AltFunc::SPI0_MOSI:     return "SPI0_MOSI";
        case AltFunc::SPI0_SCLK:     return "SPI0_SCLK";
        case AltFunc::SPI1_CE0_N:    return "SPI1_CE0_N";
        case AltFunc::SPI1_CE1_N:    return "SPI1_CE1_N";
        case AltFunc::SPI1_CE2_N:    return "SPI1_CE2_N";
        case AltFunc::SPI1_MISO:     return "SPI1_MISO";
        case AltFunc::SPI1_MOSI:     return "SPI1_MOSI";
        case AltFunc::SPI1_SCLK:     return "SPI1_SCLK";
        case AltFunc::SPI3_CE0_N:    return "SPI3_CE0_N";
        case AltFunc::SPI3_CE1_N:    return "SPI3_CE1_N";
        case AltFunc::SPI3_MISO:     return "SPI3_MISO";
        case AltFunc::SPI3_MOSI:     return "SPI3_MOSI";
        case AltFunc::SPI3_SCLK:     return "SPI3_SCLK";
        case AltFunc::SPI4_CE0_N:    return "SPI4_CE0_N";
        case AltFunc::SPI4_CE1_N:    return "SPI4_CE1_N";
        case AltFunc::SPI4_MISO:     return "SPI4_MISO";
        case AltFunc::SPI4_MOSI:     return "SPI4_MOSI";
        case AltFunc::SPI4_SCLK:     return "SPI4_SCLK";
        case AltFunc::SPI5_CE0_N:    return "SPI5_CE0_N";
        case AltFunc::SPI5_CE1_N:    return "SPI5_CE1_N";
        case AltFunc::SPI5_MISO:     return "SPI5_MISO";
        case AltFunc::SPI5_MOSI:     return "SPI5_MOSI";
        case AltFunc::SPI5_SCLK:     return "SPI5_SCLK";
        case AltFunc::SPI6_CE0_N:    return "SPI6_CE0_N";
        case AltFunc::SPI6_CE1_N:    return "SPI6_CE1_N";
        case AltFunc::SPI6_MISO:     return "SPI6_MISO";
        case AltFunc::SPI6_MOSI:     return "SPI6_MOSI";
        case AltFunc::SPI6_SCLK:     return "SPI6_SCLK";
        case AltFunc::TXD0:          return "TXD0";
        case AltFunc::RXD0:          return "RXD0";
        case AltFunc::CTS0:          return "CTS0";
        case AltFunc::RTS0:          return "RTS0";
        case AltFunc::TXD1:          return "TXD1";
        case AltFunc::RXD1:          return "RXD1";
        case AltFunc::CTS1:          return "CTS1";
        case AltFunc::RTS1:          return "RTS1";
        case AltFunc::TXD2:          return "TXD2";
        case AltFunc::RXD2:          return "RXD2";
        case AltFunc::CTS2:          return "CTS2";
        case AltFunc::RTS2:          return "RTS2";
        case AltFunc::TXD3:          return "TXD3";
        case AltFunc::RXD3:          return "RXD3";
        case AltFunc::CTS3:          return "CTS3";
        case AltFunc::RTS3:          return "RTS3";
        case AltFunc::TXD4:          return "TXD4";
        case AltFunc::RXD4:          return "RXD4";
        case AltFunc::CTS4:          return "CTS4";
        case AltFunc::RTS4:          return "RTS4";
        case AltFunc::TXD5:          return "TXD5";
        case AltFunc::RXD5:          return "RXD5";
        case AltFunc::CTS5:          return "CTS5";
        case AltFunc::RTS5:          return "RTS5";
        case AltFunc::GPCLK0:        return "GPCLK0";
        case AltFunc::GPCLK1:        return "GPCLK1";
        case AltFunc::GPCLK2:        return "GPCLK2";
        case AltFunc::PWM0:          return "PWM0";
        case AltFunc::PWM1:          return "PWM1";
        case AltFunc::PCM_CLK:       return "PCM_CLK";
        case AltFunc::PCM_FS:        return "PCM_FS";
        case AltFunc::PCM_DIN:       return "PCM_DIN";
        case AltFunc::PCM_DOUT:      return "PCM_DOUT";
        case AltFunc::ARM_TDI:       return "ARM_TDI";
        case AltFunc::ARM_TDO:       return "ARM_TDO";
        case AltFunc::ARM_TMS:       return "ARM_TMS";
        case AltFunc::ARM_TCK:       return "ARM_TCK";
        case AltFunc::ARM_RTCK:      return "ARM_RTCK";
        case AltFunc::ARM_TRST:      return "ARM_TRST";
        case AltFunc::PCLK:          return "PCLK";
        case AltFunc::DE:            return "DE";
        case AltFunc::LCD_VSYNC:     return "LCD_VSYNC";
        case AltFunc::LCD_HSYNC:     return "LCD_HSYNC";
        case AltFunc::DPI_D0:        return "DPI_D0";
        case AltFunc::DPI_D1:        return "DPI_D1";
        case AltFunc::DPI_D2:        return "DPI_D2";
        case AltFunc::DPI_D3:        return "DPI_D3";
        case AltFunc::DPI_D4:        return "DPI_D4";
        case AltFunc::DPI_D5:        return "DPI_D5";
        case AltFunc::DPI_D6:        return "DPI_D6";
        case AltFunc::DPI_D7:        return "DPI_D7";
        case AltFunc::DPI_D8:        return "DPI_D8";
        case AltFunc::DPI_D9:        return "DPI_D9";
        case AltFunc::DPI_D10:       return "DPI_D10";
        case AltFunc::DPI_D11:       return "DPI_D11";
        case AltFunc::DPI_D12:       return "DPI_D12";
        case AltFunc::DPI_D13:       return "DPI_D13";
        case AltFunc::DPI_D14:       return "DPI_D14";
        case AltFunc::DPI_D15:       return "DPI_D15";
        case AltFunc::DPI_D16:       return "DPI_D16";
        case AltFunc::DPI_D17:       return "DPI_D17";
        case AltFunc::DPI_D18:       return "DPI_D18";
        case AltFunc::DPI_D19:       return "DPI_D19";
        case AltFunc::DPI_D20:       return "DPI_D20";
        case AltFunc::DPI_D21:       return "DPI_D21";
        case AltFunc::DPI_D22:       return "DPI_D22";
        case AltFunc::DPI_D23:       return "DPI_D23";
        case AltFunc::SA0:           return "SA0";
        case AltFunc::SA1:           return "SA1";
        case AltFunc::SA2:           return "SA2";
        case AltFunc::SA3:           return "SA3";
        case AltFunc::SA4:           return "SA4";
        case AltFunc::SA5:           return "SA5";
        case AltFunc::SD0:           return "SD0";
        case AltFunc::SD1:           return "SD1";
        case AltFunc::SD2:           return "SD2";
        case AltFunc::SD3:           return "SD3";
        case AltFunc::SD4:           return "SD4";
        case AltFunc::SD5:           return "SD5";
        case AltFunc::SD6:           return "SD6";
        case AltFunc::SD7:           return "SD7";
        case AltFunc::SD8:           return "SD8";
        case AltFunc::SD9:           return "SD9";
        case AltFunc::SD10:          return "SD10";
        case AltFunc::SD11:          return "SD11";
        case AltFunc::SD12:          return "SD12";
        case AltFunc::SD13:          return "SD13";
        case AltFunc::SD14:          return "SD14";
        case AltFunc::SD15:          return "SD15";
        case AltFunc::SD16:          return "SD16";
        case AltFunc::SD17:          return "SD17";
        case AltFunc::SD0_CLK:       return "SD0_CLK";
        case AltFunc::SD0_CMD:       return "SD0_CMD";
        case AltFunc::SD0_DAT0:      return "SD0_DAT0";
        case AltFunc::SD0_DAT1:      return "SD0_DAT1";
        case AltFunc::SD0_DAT2:      return "SD0_DAT2";
        case AltFunc::SD0_DAT3:      return "SD0_DAT3";
        case AltFunc::SD1_CLK:       return "SD1_CLK";
        case AltFunc::SD1_CMD:       return "SD1_CMD";
        case AltFunc::SD1_DAT0:      return "SD1_DAT0";
        case AltFunc::SD1_DAT1:      return "SD1_DAT1";
        case AltFunc::SD1_DAT2:      return "SD1_DAT2";
        case AltFunc::SD1_DAT3:      return "SD1_DAT3";
        case AltFunc::SOE_N:         return "SOE_N";
        case AltFunc::SWE_N:         return "SWE_N";
        case AltFunc::FL0:           return "FL0";
        case AltFunc::FL1:           return "FL1";
        case AltFunc::TE0:           return "TE0";
        case AltFunc::TE1:           return "TE1";
        case AltFunc::I2CSL_CE_N:    return "I2CSL_CE_N";
        case AltFunc::I2CSL_SDI:     return "I2CSL_SDI";
        case AltFunc::I2CSL_SDA:     return "I2CSL_SDA";
        case AltFunc::I2CSL_SCL:     return "I2CSL_SCL";

        default:                     return "UNKNOWN";
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

std::string Raspberry::getModelName() {
    return name;
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
    if (!text.empty() && text.back() == '\r'){ //Dodane ze względu na to, że nowa linia w pliku txt jest odczytywana jako \r dlatego nie przypisywał popranej wartości
        text.pop_back();
    }

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
    auto getActiveRole = [](const Pin& pin)
    {
        switch (pin.getType())
        {
            case Type::Ground: return std::string("GND");
            case Type::VCC_3V3: return std::string("3V3");
            case Type::VCC_5V:  return std::string("5V");
            case Type::GPIO:    return altFuncToString(pin.getCurrentFunc());
        }

        return std::string("UNKNOWN");
    };

    std::cout << "\n";
    std::cout << "=============================================================== PINOUT ===============================================================\n";

    std::cout << std::left
              << std::setw(6)  << "PIN"
              << std::setw(6)  << "BCM"
              << std::setw(9)  << "MODE"
              << std::setw(8)  << "LEVEL"
              << std::setw(8)  << "PULL"
              << std::setw(18) << "ACTIVE ROLE"
              << "    "
              << std::setw(6)  << "PIN"
              << std::setw(6)  << "BCM"
              << std::setw(9)  << "MODE"
              << std::setw(8)  << "LEVEL"
              << std::setw(8)  << "PULL"
              << "ACTIVE ROLE"
              << "\n";

    std::cout << "------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 20; i++)
    {
        Pin& left = pins[i * 2];
        Pin& right = pins[i * 2 + 1];

        std::string leftMode;
        if (left.getDirection() == Direction::Input)
            leftMode = "INPUT";
        else if (left.getDirection() == Direction::Output)
            leftMode = "OUTPUT";
        else
            leftMode = "--";

        std::string leftLevel;
        if (left.getValue() == Level::High)
            leftLevel = "HIGH";
        else if (left.getValue() == Level::Low)
            leftLevel = "LOW";
        else
            leftLevel = "--";

        std::string leftPull;
        if (left.getPull() == Pull::Up)
            leftPull = "UP";
        else if (left.getPull() == Pull::Down)
            leftPull = "DOWN";
        else
            leftPull = "--";


        std::string rightMode;
        if (right.getDirection() == Direction::Input)
            rightMode = "INPUT";
        else if (right.getDirection() == Direction::Output)
            rightMode = "OUTPUT";
        else
            rightMode = "--";

        std::string rightLevel;
        if (right.getValue() == Level::High)
            rightLevel = "HIGH";
        else if (right.getValue() == Level::Low)
            rightLevel = "LOW";
        else
            rightLevel = "--";

        std::string rightPull;
        if (right.getPull() == Pull::Up)
            rightPull = "UP";
        else if (right.getPull() == Pull::Down)
            rightPull = "DOWN";
        else
            rightPull = "--";


        std::string leftRole = getActiveRole(left);
        std::string rightRole = getActiveRole(right);


        std::cout << std::left
                  << std::setw(6)  << left.getId()
                  << std::setw(6)  << left.getBcm()
                  << std::setw(9)  << leftMode
                  << std::setw(8)  << leftLevel
                  << std::setw(8)  << leftPull
                  << std::setw(18) << leftRole

                  << "    "

                  << std::setw(6)  << right.getId()
                  << std::setw(6)  << right.getBcm()
                  << std::setw(9)  << rightMode
                  << std::setw(8)  << rightLevel
                  << std::setw(8)  << rightPull
                  << rightRole

                  << "\n";
    }

    std::cout << "====================================================================================================================================\n";
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

    if (pin.getCurrentFunc() != AltFunc::GPIO)
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() +
                      ") jest w trybie alt (" + altFuncToString(pin.getCurrentFunc()) +
                      ") - stan mozna ustawiac tylko w trybie GPIO. Najpierw ustaw funkcje GPIO (opcja 5).");
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

    if (pin.getCurrentFunc() != AltFunc::GPIO)
    {
        UI::showError("Pin " + std::to_string(pinId) + " (" + pin.getName() +
                      ") jest w trybie alt (" + altFuncToString(pin.getCurrentFunc()) +
                      ") - tryb wejscie/wyjscie mozna zmieniac tylko w trybie GPIO. Najpierw ustaw funkcje GPIO (opcja 5).");
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
