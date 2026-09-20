#include "../models/Raspberry.h"

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

namespace 
{
    void clearScreen()
    {
        std::cout << "\033[2J\033[H";
    }

    void pauseScreen()
    {
        std::cout << "\n  " << UI::DIM << UI::GRAY 
                  << "+-- Nacisnij " << UI::RESET << UI::CYAN << "[ENTER]" << UI::RESET 
                  << UI::DIM << UI::GRAY << ", aby wrocic do menu glownego..." << UI::RESET;
        std::cin.get();
    }

    void printHeader(const std::string& modelName, const std::string& breadcrumb = "")
    {
        const int width = 62;
        std::cout << UI::CYAN << UI::BOLD;
        std::cout << "\n  +" << std::string(width, '=') << "+\n";
        
        std::string title = "RASPBERRY PI " + modelName + " - CONTROL PANEL";
        int pad = (width - title.length()) / 2;
        std::cout << "  |" << std::string(pad, ' ') << title 
                  << std::string(width - pad - title.length(), ' ') << "|\n";
        
        std::cout << "  +" << std::string(width, '=') << "+\n" << UI::RESET;

        if (!breadcrumb.empty())
        {
            std::cout << "  " << UI::DIM << UI::GRAY << "  >> Home >> " << UI::RESET 
                      << UI::CYAN << breadcrumb << UI::RESET << "\n";
        }
    }

    void printMenuBox(const std::string& title)
    {
        std::cout << "\n  " << UI::BLUE << "+--- " << UI::BOLD << UI::WHITE << title 
                  << UI::RESET << UI::BLUE << " " 
                  << std::string(std::max(0, 50 - (int)title.length()), '-') 
                  << "+" << UI::RESET << "\n";
    }

    void printMenuItem(const std::string& key, const std::string& label, const std::string& desc = "")
    {
        std::cout << "  " << UI::BLUE << "|  " << UI::RESET
                  << UI::CYAN << "[" << key << "]" << UI::RESET 
                  << " " << UI::BOLD << label << UI::RESET;
        
        if (!desc.empty())
        {
            int pad = 25 - label.length();
            if (pad < 1) pad = 1;
            std::cout << std::string(pad, ' ') << UI::DIM << UI::GRAY << desc << UI::RESET;
        }
        std::cout << "\n";
    }

    void printMenuFooter()
    {
        std::cout << "  " << UI::BLUE << "+" << std::string(56, '-') << "+" << UI::RESET << "\n";
    }

    void printMainMenu()
    {
        printMenuBox("MENU GLOWNE");
        printMenuItem("1", "Pokaz pinout",           "Wyswietl mape pinow plytki");
        printMenuItem("2", "Zmien pull",             "Ustaw rezystor PULL UP/DOWN");
        printMenuItem("3", "Przelacz stan pinu",     "Ustaw HIGH / LOW");
        printMenuItem("4", "Zmien tryb pinu",        "Ustaw INPUT / OUTPUT");
        printMenuItem("5", "Funkcja alternatywna",   "Wybierz tryb pracy pinu");
        std::cout << "  " << UI::BLUE << "|" << UI::RESET << "\n";
        printMenuItem("0", "Wyjdz",                  "Zakoncz program");
        printMenuFooter();
    }

    int readChoice()
    {
        std::cout << "\n  " << UI::GREEN << ">> " << UI::BOLD << "Wybierz opcje" << UI::RESET << ": ";
        int choice;
        if (std::cin >> choice)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    void printSectionTitle(const std::string& title)
    {
        std::cout << "\n  " << UI::BG_BLUE << "  " << title << "  " << UI::RESET << "\n";
    }
}

int main()
{
    Raspberry rpi("4B");
    bool running = true;

    while (running)
    {
        clearScreen();
        printHeader(rpi.getModelName());
        printMainMenu();

        int choice = readChoice();

        switch (choice)
        {
            case 0:
                running = false;
                continue;

            case 1:
                clearScreen();
                printHeader(rpi.getModelName(), "Pokaz pinout");
                printSectionTitle("[*] PINOUT PLYTKI");
                rpi.displayPins();
                pauseScreen();
                break;

            case 2:
                clearScreen();
                printHeader(rpi.getModelName(), "Zmien PULL");
                printSectionTitle("[~] USTAWIENIA REZYSTORA PULL");
                rpi.changePull();
                pauseScreen();
                break;

            case 3:
                clearScreen();
                printHeader(rpi.getModelName(), "Przelacz pin");
                printSectionTitle("[!] PRZELACZANIE STANU PINU");
                rpi.togglePin();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                printHeader(rpi.getModelName(), "Zmien tryb pinu");
                printSectionTitle("[<>] ZMIANA KIERUNKU PINU");
                rpi.changePinMode();
                pauseScreen();
                break;

            case 5:
                clearScreen();
                printHeader(rpi.getModelName(), "Funkcja alternatywna");
                printSectionTitle("[+] FUNKCJE ALTERNATYWNE (ALT)");
                rpi.selectAlternateFunction();
                pauseScreen();
                break;

            default:
                UI::showError("Nieprawidlowa opcja! Wybierz numer z menu.");
                pauseScreen();
                break;
        }
    }

    clearScreen();
    std::cout << "\n\n";
    std::cout << "  " << UI::CYAN << UI::BOLD;
    std::cout << "  +==========================================+\n";
    std::cout << "  |                                          |\n";
    std::cout << "  |        Dziekuje za skorzystanie!         |\n";
    std::cout << "  |                                          |\n";
    std::cout << "  |       Do zobaczenia nastepnym razem      |\n";
    std::cout << "  |                                          |\n";
    std::cout << "  +==========================================+\n";
    std::cout << UI::RESET << "\n";
    return 0;
}