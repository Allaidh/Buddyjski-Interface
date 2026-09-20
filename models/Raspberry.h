#pragma once

#include "Pin.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

std::string altFuncToString(AltFunc func);
namespace UI
{
    const std::string RESET      = "\033[0m";
    const std::string BOLD       = "\033[1m";
    const std::string DIM        = "\033[2m";

    const std::string CYAN       = "\033[1;36m";
    const std::string GREEN      = "\033[1;32m";
    const std::string YELLOW     = "\033[1;33m";
    const std::string RED        = "\033[1;31m";
    const std::string BLUE       = "\033[1;34m";
    const std::string MAGENTA    = "\033[1;35m";
    const std::string WHITE      = "\033[1;37m";
    const std::string GRAY       = "\033[90m";

    const std::string BG_BLUE    = "\033[44;1;37m";
    const std::string BG_GREEN   = "\033[42;1;30m";
    const std::string BG_RED     = "\033[41;1;37m";
    const std::string BG_5V      = "\033[41;1;37m";
    const std::string BG_3V3     = "\033[43;1;30m";
    const std::string BG_GND     = "\033[100;1;37m";
    const std::string BG_ALT     = "\033[45;1;37m";

    inline void showSuccess(const std::string& msg)
    {
        std::cout << "\n  " << GREEN << "[+] SUKCES: " << RESET << BOLD << msg << RESET << "\n";
    }

    inline void showError(const std::string& msg)
    {
        std::cout << "\n  " << RED << "[!] BLAD:   " << RESET << BOLD << msg << RESET << "\n";
    }

    inline void printPinCardHeader(int id, const std::string& name)
    {
        std::cout << "\n  " << BLUE << "+-- STATUS PINU ID: " << BOLD << YELLOW 
                  << std::setw(2) << std::setfill('0') << id << RESET << BLUE 
                  << " (" << name << ") " 
                  << std::string(std::max(0, 17 - (int)name.length()), '-') 
                  << "+" << RESET << "\n";
    }

    inline void printPinCardRow(const std::string& label, const std::string& valColor, const std::string& value)
    {
        std::cout << "  " << BLUE << "|  " << RESET 
                  << std::left << std::setw(18) << std::setfill(' ') << label << ": " 
                  << valColor << BOLD << value << RESET << "\n";
    }

    inline void printPinCardFooter()
    {
        std::cout << "  " << BLUE << "+" << std::string(45, '-') << "+" << RESET << "\n";
    }

    inline void printPrompt(const std::string& text)
    {
        std::cout << "\n  " << GREEN << ">> " << BOLD << text << RESET << ": ";
    }

    inline int getValidatedPinId()
    {
        printPrompt("Podaj ID pinu (1-40)");
        int pinId;
        if (!(std::cin >> pinId) || pinId < 1 || pinId > 40)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showError("Niepoprawny numer ID! Podaj liczbe od 1 do 40.");
            return -1;
        }
        return pinId;
    }

    inline int getValidatedChoice(int minOpt, int maxOpt)
    {
        printPrompt("Wybierz opcje");
        int choice;
        if (!(std::cin >> choice) || choice < minOpt || choice > maxOpt)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showError("Niepoprawny wybor! Wybierz wlasciwy numer opcji.");
            return -1;
        }
        return choice;
    }
}

class Raspberry
{
private:
    Pin pins[40];
    std::string name;

public:
    Raspberry(std::string name);

    Pull parsePull(std::string text);
    Level parseLevel(std::string text);
    Direction parseDirection(std::string text);
    Type parseType(std::string text);

    void displayPins();
    void changePull();
    void togglePin();
    void changePinMode();
    void selectAlternateFunction();
};