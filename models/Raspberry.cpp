#include "Pin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
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
        printPinName(leftPin, false); // wyrównanie do prawej
        std::cout << "│";

        // Fizyczne ID na środku (pogrubione, ułatwia lokalizację)
        std::cout << BOLD << " " << std::setw(2) << std::setfill('0') << leftPin.getId() << " " << RESET << "│";
        std::cout << BOLD << " " << std::setw(2) << std::setfill('0') << rightPin.getId() << " " << RESET << "│";

        printPinName(rightPin, true); // wyrównanie do lewej
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

    // --- LEGENDA NA DOLE ---
    std::cout << " Legenda: " 
              << BG_5V << "  5V  " << RESET << " Power "
              << BG_3V3 << " 3.3V " << RESET << " Power "
              << BG_GND << " GND " << RESET << " Ground "
              << T_GREEN << "● GPIO" << RESET << " General Purpose I/O\n\n";
}};
