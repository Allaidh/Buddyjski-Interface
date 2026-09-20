#include "../models/Raspberry.cpp"

#include <iostream>
#include <limits>
#include <string>

namespace
{
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string CYAN = "\033[1;36m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string RED = "\033[1;31m";

void clearScreen()
{
    std::cout << "\033[2J\033[H";
}

void printHeader()
{
    std::cout << CYAN << BOLD;
    std::cout << "\n  +----------------------------------------------------------+\n";
    std::cout << "  |                      RASPBERRY PI CLI                  |\n";
    std::cout << "  +----------------------------------------------------------+\n";
    std::cout << RESET;
}

void printMenu()
{
    std::cout << "\n  " << BOLD << "MENU GŁÓWNE" << RESET << "\n";
    std::cout << "  " << CYAN << "[1]" << RESET << " Pokaż pinout\n";
    std::cout << "  " << CYAN << "[2]" << RESET << " Zmień pull\n";
    std::cout << "  " << CYAN << "[3]" << RESET << " Włącz/wyłącz pin\n";
    std::cout << "  " << CYAN << "[4]" << RESET << " Zmień tryb pinu\n";
    std::cout << "  " << CYAN << "[5]" << RESET << " Wybierz funkcję alternatywną\n";
    std::cout << "  " << CYAN << "[0]" << RESET << " Wyjdź\n";
    std::cout << "\n  " << BOLD << "Wybierz opcję: " << RESET;
}

int readChoice()
{
    int choice;
    if (std::cin >> choice)
    {
        return choice;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
}
}

int main()
{
    Raspberry rpi("4b");
    bool running = true;

    while (running)
    {
        clearScreen();
        printHeader();
        printMenu();

        switch (readChoice())
        {
            case 0:
                std::cout << "\n  " << YELLOW << "Zamykanie programu..." << RESET << "\n";
                running = false;
                continue;
            case 1:
                clearScreen();
                rpi.displayPins();
                break;
            case 2:
                clearScreen();
                rpi.changePull();
                break;
            case 3:
                clearScreen();
                rpi.togglePin();
                break;
            case 4:
                clearScreen();
                rpi.changePinMode();
                break;
            case 5:
                clearScreen();
                rpi.selectAlternateFunction();
                break;
            default:
                std::cout << "\n  " << RED << "Podaj poprawną opcję z menu."
                          << RESET << "\n";
                break;
        }

        std::cout << "\n  " << CYAN << "Naciśnij ENTER, aby wrócić do menu głównego...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    clearScreen();
    std::cout << "\n  " << GREEN << "Żegnaj!" << RESET << "\n\n";
    return 0;
}