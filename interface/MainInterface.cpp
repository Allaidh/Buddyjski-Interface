#include "../models/Raspberry.h"

#include <iostream>
#include <string>

using namespace std;

void clearScreen()
{
    system("clear");
}

void pauseScreen()
{
    cout << "\n" << UI::DIM << UI::GRAY << "Nacisnij " << UI::RESET
         << UI::CYAN << "[ENTER]" << UI::RESET
         << UI::DIM << UI::GRAY << ", aby wrocic do menu..." << UI::RESET;
    cin.get();
}

void printHeader()
{
    cout << UI::CYAN << "================================================\n" << UI::RESET;
    cout << UI::BOLD << UI::WHITE << "  RASPBERRY PI - CONTROL PANEL\n" << UI::RESET;
    cout << UI::CYAN << "================================================\n" << UI::RESET;
}

void printMenu()
{
    cout << UI::BLUE << UI::BOLD << "\n  MENU GLOWNE\n\n" << UI::RESET;
    cout << "  " << UI::CYAN << "1." << UI::RESET << " Pokaz pinout\n";
    cout << "  " << UI::CYAN << "2." << UI::RESET << " Zmien pull\n";
    cout << "  " << UI::CYAN << "3." << UI::RESET << " Przelacz stan pinu\n";
    cout << "  " << UI::CYAN << "4." << UI::RESET << " Zmien tryb pinu\n";
    cout << "  " << UI::CYAN << "5." << UI::RESET << " Funkcja alternatywna\n";
    cout << "  " << UI::CYAN << "0." << UI::RESET << " Wyjdz\n";
}

int main()
{
    Raspberry rpi("test");
    bool running = true;

    while (running)
    {
        clearScreen();
        printHeader();
        printMenu();

        int choice;
        cout << "\n" << UI::GREEN << ">> " << UI::BOLD << "Wybierz opcje" << UI::RESET << ": ";
        cin >> choice;

        // walidacja (czy liczba)
        if (cin.fail())
        {
            cin.clear();
            choice = -1;
        }
        cin.ignore(1000, '\n');

        switch (choice)
        {
            case 0:
                running = false;
                break;

            case 1:
                clearScreen();
                printHeader();
                cout << "\n" << UI::BLUE << UI::BOLD << "--- PINOUT PLYTKI ---\n" << UI::RESET;
                rpi.displayPins();
                pauseScreen();
                break;

            case 2:
                clearScreen();
                printHeader();
                cout << "\n" << UI::BLUE << UI::BOLD << "--- USTAWIENIA REZYSTORA PULL ---\n" << UI::RESET;
                rpi.changePull();
                pauseScreen();
                break;

            case 3:
                clearScreen();
                printHeader();
                cout << "\n" << UI::BLUE << UI::BOLD << "--- PRZELACZANIE STANU PINU ---\n" << UI::RESET;
                rpi.togglePin();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                printHeader();
                cout << "\n" << UI::BLUE << UI::BOLD << "--- ZMIANA TRYBU PINU ---\n" << UI::RESET;
                rpi.changePinMode();
                pauseScreen();
                break;

            case 5:
                clearScreen();
                printHeader();
                cout << "\n" << UI::BLUE << UI::BOLD << "--- FUNKCJE ALTERNATYWNE ---\n" << UI::RESET;
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

    return 0;
}