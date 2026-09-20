#include "Pin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

namespace
{
std::string altFuncName(AltFunc function)
{
    switch (function)
    {
        case AltFunc::NONE: return "NONE";
        case AltFunc::GPIO: return "GPIO";
        case AltFunc::I2C4_SDA: return "I2C4_SDA";
        case AltFunc::I2C4_SCL: return "I2C4_SCL";
        case AltFunc::AP_I2C2_SCL: return "AP_I2C2_SCL";
        case AltFunc::AP_I2C2_SDA: return "AP_I2C2_SDA";
        case AltFunc::AP_I2C3_SCL: return "AP_I2C3_SCL";
        case AltFunc::AP_I2C3_SDA: return "AP_I2C3_SDA";
        case AltFunc::AP_I2C4_SCL: return "AP_I2C4_SCL";
        case AltFunc::AP_I2C4_SDA: return "AP_I2C4_SDA";
        case AltFunc::R_I2C0_SCL: return "R_I2C0_SCL";
        case AltFunc::R_I2C0_SDA: return "R_I2C0_SDA";
        case AltFunc::I2C3_SCL: return "I2C3_SCL";
        case AltFunc::I2C3_SDA: return "I2C3_SDA";
        case AltFunc::UART1_TXD: return "UART1_TXD";
        case AltFunc::UART1_RXD: return "UART1_RXD";
        case AltFunc::UART1_CTS_N: return "UART1_CTS_N";
        case AltFunc::UART1_RTS_N: return "UART1_RTS_N";
        case AltFunc::UART4_TXD: return "UART4_TXD";
        case AltFunc::UART4_RXD: return "UART4_RXD";
        case AltFunc::UART4_CTS_N: return "UART4_CTS_N";
        case AltFunc::UART5_TXD: return "UART5_TXD";
        case AltFunc::UART5_RXD: return "UART5_RXD";
        case AltFunc::UART5_CTS_N: return "UART5_CTS_N";
        case AltFunc::UART5_RTS_N: return "UART5_RTS_N";
        case AltFunc::UART8_TXD: return "UART8_TXD";
        case AltFunc::UART8_RXD: return "UART8_RXD";
        case AltFunc::UART8_CTSN: return "UART8_CTSN";
        case AltFunc::UART8_RTS_N: return "UART8_RTS_N";
        case AltFunc::UART9_TXD: return "UART9_TXD";
        case AltFunc::UART9_RXD: return "UART9_RXD";
        case AltFunc::R_UART0_TXD: return "R_UART0_TXD";
        case AltFunc::R_UART1_RXD: return "R_UART1_RXD";
        case AltFunc::R_UART1_TXD: return "R_UART1_TXD";
        case AltFunc::R_UART1_CTS_N: return "R_UART1_CTS_N";
        case AltFunc::R_UART1_RTS_N: return "R_UART1_RTS_N";
        case AltFunc::R_SPI_RXD: return "R_SPI_RXD";
        case AltFunc::R_SPI_TXD: return "R_SPI_TXD";
        case AltFunc::R_SPI_SCLK: return "R_SPI_SCLK";
        case AltFunc::R_SPI_FRM: return "R_SPI_FRM";
        case AltFunc::SPI2_TXD: return "SPI2_TXD";
        case AltFunc::SPI2_RXD: return "SPI2_RXD";
        case AltFunc::SPI2_SCLK: return "SPI2_SCLK";
        case AltFunc::SPI2_FRM: return "SPI2_FRM";
        case AltFunc::SPI3_TXD: return "SPI3_TXD";
        case AltFunc::SPI3_RXD: return "SPI3_RXD";
        case AltFunc::SPI3_SCLK: return "SPI3_SCLK";
        case AltFunc::SPI3_FRM: return "SPI3_FRM";
        case AltFunc::DCLK_SPI_LCD: return "DCLK_SPI_LCD";
        case AltFunc::DCX_DOUT1_SPI_LCD: return "DCX_DOUT1_SPI_LCD";
        case AltFunc::DIN_SPI_LCD: return "DIN_SPI_LCD";
        case AltFunc::DOUT0_SPI_LCD: return "DOUT0_SPI_LCD";
        case AltFunc::CS_SPI_LCD: return "CS_SPI_LCD";
        case AltFunc::PWM1: return "PWM1";
        case AltFunc::PWM2: return "PWM2";
        case AltFunc::PWM3: return "PWM3";
        case AltFunc::PWM4: return "PWM4";
        case AltFunc::PWM5: return "PWM5";
        case AltFunc::PWM7: return "PWM7";
        case AltFunc::PWM8: return "PWM8";
        case AltFunc::PWM9: return "PWM9";
        case AltFunc::PWM16: return "PWM16";
        case AltFunc::R_PWM0: return "R_PWM0";
        case AltFunc::R_PWM1: return "R_PWM1";
        case AltFunc::R_PWM4: return "R_PWM4";
        case AltFunc::R_PWM5: return "R_PWM5";
        case AltFunc::R_PWM6: return "R_PWM6";
        case AltFunc::R_PWM7: return "R_PWM7";
        case AltFunc::R_PWM8: return "R_PWM8";
        case AltFunc::CAN_TX0: return "CAN_TX0";
        case AltFunc::CAN_RX0: return "CAN_RX0";
        case AltFunc::R_CAN_TX0: return "R_CAN_TX0";
        case AltFunc::R_I2S3_LRCK: return "R_I2S3_LRCK";
        case AltFunc::R_I2S3_SCLK: return "R_I2S3_SCLK";
        case AltFunc::GMAC1_TX: return "GMAC1_TX";
        case AltFunc::GMAC1_TX_D0: return "GMAC1_TX_D0";
        case AltFunc::GMAC1_TX_D2: return "GMAC1_TX_D2";
        case AltFunc::GMAC1_TX_D3: return "GMAC1_TX_D3";
        case AltFunc::GMAC1_RX_D0: return "GMAC1_RX_D0";
        case AltFunc::GMAC1_RX_D1: return "GMAC1_RX_D1";
        case AltFunc::GMAC1_RX_D2: return "GMAC1_RX_D2";
        case AltFunc::GMAC1_RX_D3: return "GMAC1_RX_D3";
        case AltFunc::GMAC1_RXDV: return "GMAC1_RXDV";
        case AltFunc::GMAC1_RX_CLK: return "GMAC1_RX_CLK";
        case AltFunc::GMAC1_CLK_REF: return "GMAC1_CLK_REF";
        case AltFunc::PCIe0_PERSTN: return "PCIe0_PERSTN";
        case AltFunc::PCIe0_WAKEN: return "PCIe0_WAKEN";
        case AltFunc::PCIe0_CLKREQN: return "PCIe0_CLKREQN";
        case AltFunc::PCIe1_PERSTN: return "PCIe1_PERSTN";
        case AltFunc::PCIe1_WAKEN: return "PCIe1_WAKEN";
        case AltFunc::PCIe1_CLKREQN: return "PCIe1_CLKREQN";
        case AltFunc::PCIe2_PERSTN: return "PCIe2_PERSTN";
        case AltFunc::PCIe2_WAKEN: return "PCIe2_WAKEN";
        case AltFunc::PCIe2_CLKREQN: return "PCIe2_CLKREQN";
        case AltFunc::PRI_TDI: return "PRI_TDI";
        case AltFunc::PRI_TMS: return "PRI_TMS";
        case AltFunc::PRI_TCK: return "PRI_TCK";
        case AltFunc::PRI_TDO: return "PRI_TDO";
        case AltFunc::MN_CLK: return "MN_CLK";
        case AltFunc::MN_CLK2: return "MN_CLK2";
        case AltFunc::VCXO_OUT: return "VCXO_OUT";
        case AltFunc::DSI_TE: return "DSI_TE";
        case AltFunc::_32K_OUT: return "32K_OUT";
        case AltFunc::R_IR_RX: return "R_IR_RX";
        case AltFunc::ONE_WIRE: return "ONE_WIRE";
        case AltFunc::KP_MKOUT_2: return "KP_MKOUT_2";
        case AltFunc::KP_MKOUT_3: return "KP_MKOUT_3";
        case AltFunc::KP_MKIN_3: return "KP_MKIN_3";
    }

    return "UNKNOWN";
}
}

class Raspberry
{
private:
    Pin pins[40];
    std::string name;
    
public:
Raspberry(std::string name)
{
    this->name = name;

    std::ifstream file("pins.txt");

    if (!file.is_open())
    {
        std::cout << "Nie mozna otworzyc pliku pins.txt\n";
        return;
    }

    std::string line;

    for (size_t i = 0; i < 40; i++)
    {
        if (!std::getline(file, line))
        {
            std::cout << "Blad: plik zawiera mniej niz 40 wierszy\n";
            break;
        }

        std::stringstream ss(line);

        std::string id;
        std::string bcm;
        std::string pinName;
        std::string type;
        std::string pull;
        std::string value;
        std::string direction;

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
        {
            pinBcm = std::stoi(bcm);
        }

        pins[i] = Pin(
            pinId,
            pinBcm,
            pinName,
            parseType(type),
            parsePull(pull),
            parseLevel(value),
            parseDirection(direction)
        );
    }

    file.close();
    }

    Pull parsePull(std::string text)
    {
        if (text == "up")
            return Pull::Up;

        if (text == "down")
            return Pull::Down;

        return Pull::None;
    }
    Level parseLevel(std::string text)
    {
        if (text == "low")
            return Level::Low;

        if (text == "high")
            return Level::High;

        return Level::None;
    }
    Direction parseDirection(std::string text)
    {
        if (text == "input")
            return Direction::Input;

        if (text == "output")
            return Direction::Output;

        return Direction::None;
    }
    Type parseType(std::string text)
    {
        if(text == "Ground")
            return Type::Ground;
        if(text == "VCC_3V3")
            return Type::VCC_3V3;
        if(text == "VCC_5V")
            return Type::VCC_5V;
        if(text == "GPIO")
            return Type::GPIO;
    }
void displayPins()
{
    // --- KOLORY ANSI (Wersja Premium) ---
    const std::string RESET      = "\033[0m";
    const std::string BOLD       = "\033[1m";
    const std::string GRAY       = "\033[90m";
    const std::string WHITE      = "\033[37m";
    
    // Kolory tekstu stanu
    const std::string T_CYAN     = "\033[1;36m";
    const std::string T_YELLOW   = "\033[1;33m";
    const std::string T_GREEN    = "\033[1;32m";
    const std::string T_RED      = "\033[1;31m";
    const std::string T_BLUE     = "\033[1;34m";
    const std::string T_MAGENTA  = "\033[1;35m";

    // Kolory teł dla typów pinów (Bloki)
    const std::string BG_5V      = "\033[41;1;37m";  // Czerwone tło, biały tekst
    const std::string BG_3V3     = "\033[43;1;30m";  // Żółte tło, czarny tekst
    const std::string BG_GND     = "\033[100;1;37m"; // Ciemnoszare tło, biały tekst
    const std::string BG_GPIO    = "\033[42;1;30m";  // Zielone tło, czarny tekst (opcjonalnie, użyjemy jasnego zielonego tekstu dla czytelności)

    // --- POMOCNICZE LAMBDY DO FORMATOWANIA ---
    auto printMode = [&](Direction dir) {
        if (dir == Direction::Input)       std::cout << T_CYAN   << " INPUT" << RESET;
        else if (dir == Direction::Output) std::cout << T_YELLOW << "OUTPUT" << RESET;
        else                               std::cout << GRAY     << "  --  " << RESET;
    };

    auto printLevel = [&](Level lvl) {
        if (lvl == Level::High)      std::cout << T_GREEN << " HIGH " << RESET;
        else if (lvl == Level::Low)  std::cout << T_RED   << " LOW  " << RESET;
        else                         std::cout << GRAY    << "  --  " << RESET;
    };

    auto printPull = [&](Pull pull) {
        if (pull == Pull::Up)         std::cout << T_BLUE    << "  UP  " << RESET;
        else if (pull == Pull::Down)  std::cout << T_MAGENTA << " DOWN " << RESET;
        else                          std::cout << GRAY      << "  --  " << RESET;
    };

    auto printBcm = [&](int bcm) {
        if (bcm <= 0) std::cout << GRAY << " -- " << RESET;
        else          std::cout << " " << std::setw(2) << std::setfill(' ') << bcm << " ";
    };

    auto printPinName = [&](const Pin& pin, bool leftAlign) {
        std::string name = pin.getName();
        if (name.length() > 16) name = name.substr(0, 13) + "...";

        // Dopełnienie spacji dla równego wyrównania
        int pad = 16 - name.length();
        std::string padded = leftAlign ? (name + std::string(pad, ' ')) : (std::string(pad, ' ') + name);

        // Stylowanie w zależności od typu pinu
        switch (pin.getType())
        {
            case Type::VCC_5V:
                std::cout << BG_5V << padded << RESET;
                break;
            case Type::VCC_3V3:
                std::cout << BG_3V3 << padded << RESET;
                break;
            case Type::Ground:
                std::cout << BG_GND << padded << RESET;
                break;
            case Type::GPIO:
                std::cout << T_GREEN << padded << RESET;
                break;
            default:
                std::cout << GRAY << padded << RESET;
                break;
        }
    };

    // --- NAGŁÓWEK TABELI ---
    std::cout << "\n" << BOLD << T_CYAN;
    std::cout << " ┌" << std::string(94, '─') << "┐\n";
    
    // Wyśrodkowany tytuł
    std::string title = name + " - PHYSICAL PINOUT MAP";
    int titlePad = (94 - title.length()) / 2;
    std::cout << " │" << std::string(titlePad, ' ') << title << std::string(94 - titlePad - title.length(), ' ') << "│\n";
    
    std::cout << " └" << std::string(94, '─') << "┘\n" << RESET;

    // Szablony linii tabeli (Unicode Box-drawing)
    const std::string TOP_BORDER = " ┌──────┬──────┬──────┬────┬────────────────┬────┬────┬────────────────┬────┬──────┬──────┬──────┐\n";
    const std::string MID_BORDER = " ├──────┼──────┼──────┼────┼────────────────┼────┼────┼────────────────┼────┼──────┼──────┼──────┤\n";
    const std::string BOT_BORDER = " └──────┴──────┴──────┴────┴────────────────┴────┴────┴────────────────┴────┴──────┴──────┴──────┘\n";

    // Nagłówki kolumn
    std::cout << TOP_BORDER;
    std::cout << " │ MODE │ LVL  │ PULL │BCM │    PIN NAME    │ ID │ ID │    PIN NAME    │BCM │ PULL │ LVL  │ MODE │\n";
    std::cout << MID_BORDER;

    // --- RENDEROWANIE PINÓW (Pętla po 20 wierszy - 40 pinów parzyście/nieparzyście) ---
    for (int r = 0; r < 20; r++)
    {
        // Lewa strona: piny nieparzyste (1, 3, 5...) -> indeksy 0, 2, 4...
        // Prawa strona: piny parzyste (2, 4, 6...) -> indeksy 1, 3, 5...
        Pin& leftPin  = pins[2 * r];
        Pin& rightPin = pins[2 * r + 1];

        std::cout << " │";
        printMode(leftPin.getDirection());
        std::cout << "│";
        printLevel(leftPin.getValue());
        std::cout << "│";
        printPull(leftPin.getPull());
        std::cout << "│";
        printBcm(leftPin.getBcm());
        std::cout << "│";
        printPinName(leftPin, false);
        std::cout << "│";

        std::cout << BOLD << " " << std::setw(2) << std::setfill('0') << leftPin.getId() << " " << RESET << "│";
        std::cout << BOLD << " " << std::setw(2) << std::setfill('0') << rightPin.getId() << " " << RESET << "│";

        printPinName(rightPin, true);
        std::cout << "│";
        printBcm(rightPin.getBcm());
        std::cout << "│";
        printPull(rightPin.getPull());
        std::cout << "│";
        printLevel(rightPin.getValue());
        std::cout << "│";
        printMode(rightPin.getDirection());
        std::cout << "│\n";
    }
    std::cout << BOT_BORDER;

    std::cout << " Legenda: " 
              << BG_5V << "  5V  " << RESET << " Power "
              << BG_3V3 << " 3.3V " << RESET << " Power "
              << BG_GND << " GND " << RESET << " Ground "
              << T_GREEN << "● GPIO" << RESET << " General Purpose I/O\n\n";
}

void changePull()
{
    int pinId;
    std::cout << "Podaj ID pinu (1-40): ";

    if (!(std::cin >> pinId) || pinId < 1 || pinId > 40)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny ID pinu. Wybierz numer od 1 do 40.\n";
        return;
    }

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        std::cout << "Pin " << pinId << " (" << pin.getName()
                  << ") nie jest programowalny.\n";
        return;
    }

    std::cout << "Aktualny pull: "
              << (pin.getPull() == Pull::Up ? "UP" :
                  pin.getPull() == Pull::Down ? "DOWN" : "NONE") << "\n"
              << "1. UP\n2. DOWN\n3. NONE\nWybierz: ";

    int choice;
    if (!(std::cin >> choice) || choice < 1 || choice > 3)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny wybór.\n";
        return;
    }

    pin.setPull(choice == 1 ? Pull::Up : choice == 2 ? Pull::Down : Pull::None);
    std::cout << "Pull pinu został zmieniony.\n";
}

void togglePin()
{
    int pinId;
    std::cout << "Podaj ID pinu (1-40): ";

    if (!(std::cin >> pinId) || pinId < 1 || pinId > 40)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny ID pinu. Wybierz numer od 1 do 40.\n";
        return;
    }

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        std::cout << "Pin " << pinId << " (" << pin.getName()
                  << ") nie jest programowalny.\n";
        return;
    }

    std::cout << "Aktualny stan: "
              << (pin.getValue() == Level::High ? "HIGH" :
                  pin.getValue() == Level::Low ? "LOW" : "NONE") << "\n"
              << "1. HIGH\n2. LOW\nWybierz: ";

    int choice;
    if (!(std::cin >> choice) || choice < 1 || choice > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny wybór.\n";
        return;
    }

    pin.setValue(choice == 1 ? Level::High : Level::Low);
    std::cout << "Stan pinu został zmieniony.\n";
}

void changePinMode()
{
    int pinId;
    std::cout << "Podaj ID pinu (1-40): ";

    if (!(std::cin >> pinId) || pinId < 1 || pinId > 40)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny ID pinu. Wybierz numer od 1 do 40.\n";
        return;
    }

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        std::cout << "Pin " << pinId << " (" << pin.getName()
                  << ") nie jest programowalny.\n";
        return;
    }

    std::cout << "Aktualny tryb: "
              << (pin.getDirection() == Direction::Input ? "INPUT" :
                  pin.getDirection() == Direction::Output ? "OUTPUT" : "NONE") << "\n"
              << "1. INPUT\n2. OUTPUT\nWybierz: ";

    int choice;
    if (!(std::cin >> choice) || choice < 1 || choice > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny wybór.\n";
        return;
    }

    pin.setDirection(choice == 1 ? Direction::Input : Direction::Output);
    std::cout << "Tryb pinu został zmieniony.\n";
}

void selectAlternateFunction()
{
    int pinId;
    std::cout << "Podaj ID pinu (1-40): ";

    if (!(std::cin >> pinId) || pinId < 1 || pinId > 40)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny ID pinu. Wybierz numer od 1 do 40.\n";
        return;
    }

    Pin& pin = pins[pinId - 1];
    if (!pin.getIsProgrammable())
    {
        std::cout << "Pin " << pinId << " (" << pin.getName()
                  << ") nie jest programowalny.\n";
        return;
    }

    AltFunc* availableFunctions = Pin::getAltFunctions(pin.getId());
    if (availableFunctions == nullptr)
    {
        std::cout << "Dla tego pinu nie ma dostępnych funkcji.\n";
        return;
    }

    std::cout << "Aktualna funkcja: " << altFuncName(pin.getCurrentFunc()) << "\n";
    std::cout << "Dostępne funkcje:\n";

    int availableCount = 0;
    for (int index = 0; index < 7 && availableFunctions[index] != AltFunc::NONE; ++index)
    {
        ++availableCount;
        std::cout << availableCount << ". " << altFuncName(availableFunctions[index]) << "\n";
    }

    std::cout << "Wybierz funkcję: ";
    int choice;
    if (!(std::cin >> choice) || choice < 1 || choice > availableCount)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        delete[] availableFunctions;
        std::cout << "Niepoprawny wybór.\n";
        return;
    }

    AltFunc selectedFunction = availableFunctions[choice - 1];
    bool changed = pin.setAltFunc(selectedFunction);
    delete[] availableFunctions;

    std::cout << (changed ? "Funkcja alternatywna została zmieniona.\n"
                          : "Nie udało się zmienić funkcji alternatywnej.\n");
}

};
