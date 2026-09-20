#include "../models/Raspberry.cpp"

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

namespace {

// ============================================================
//                     KOLORY ANSI
// ============================================================
const std::string RESET     = "\033[0m";
const std::string BOLD      = "\033[1m";
const std::string DIM       = "\033[2m";
const std::string ITALIC    = "\033[3m";

const std::string CYAN      = "\033[1;36m";
const std::string GREEN     = "\033[1;32m";
const std::string YELLOW    = "\033[1;33m";
const std::string RED       = "\033[1;31m";
const std::string BLUE      = "\033[1;34m";
const std::string MAGENTA   = "\033[1;35m";
const std::string WHITE     = "\033[1;37m";
const std::string GRAY      = "\033[90m";

const std::string BG_BLUE   = "\033[44;1;37m";
const std::string BG_GREEN  = "\033[42;1;30m";
const std::string BG_RED    = "\033[41;1;37m";

// ============================================================
//                     UTILITIES
// ============================================================
void clearScreen()
{
    std::cout << "\033[2J\033[H";
}

void flushInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pauseScreen()
{
    std::cout << "\n  " << DIM << GRAY 
              << "└─ Naciśnij " << RESET << CYAN << "[ENTER]" << RESET 
              << DIM << GRAY << ", aby wrócić do menu głównego..." << RESET;
    std::cin.get();
}

// Wyświetla ładne powiadomienie
void showNotification(const std::string& msg, const std::string& type = "info")
{
    std::string color, icon, label;
    if (type == "success") { color = GREEN;  icon = "✓"; label = " SUKCES  "; }
    else if (type == "error")   { color = RED;    icon = "✗"; label = "  BŁĄD   "; }
    else if (type == "warning") { color = YELLOW; icon = "!"; label = " UWAGA   "; }
    else                        { color = CYAN;   icon = "i"; label = "  INFO   "; }

    std::cout << "\n  " << color << "┃ " << icon << " " << label 
              << " ┃ " << RESET << msg << "\n";
}

// ============================================================
//                    NAGŁÓWEK / STOPKA
// ============================================================
void printHeader(const std::string& modelName, const std::string& breadcrumb = "")
{
    const int width = 62;
    std::cout << CYAN << BOLD;
    std::cout << "\n  ╔" << std::string(width, '=') << "╗\n";
    
    std::string title = "  RASPBERRY PI " + modelName + " - CONTROL PANEL";
    int pad = (width - title.length()) / 2;
    std::cout << "  ║" << std::string(pad, ' ') << title 
              << std::string(width - pad - title.length(), ' ') << "║\n";
    
    std::cout << "  ╚" << std::string(width, '=') << "╝\n" << RESET;

    if (!breadcrumb.empty())
    {
        std::cout << "  " << DIM << GRAY << "  » Home » " << RESET 
                  << CYAN << breadcrumb << RESET << "\n";
    }
}

void printMenuBox(const std::string& title)
{
    std::cout << "\n  " << BLUE << "┌─── " << BOLD << WHITE << title 
              << RESET << BLUE << " " << std::string(50 - title.length(), '-') 
              << "┐" << RESET << "\n";
}

void printMenuItem(const std::string& key, const std::string& label, const std::string& desc = "")
{
    std::cout << "  " << BLUE << "│  " << RESET
              << CYAN << "[" << key << "]" << RESET 
              << " " << BOLD << label << RESET;
    
    if (!desc.empty())
    {
        int pad = 25 - label.length();
        if (pad < 1) pad = 1;
        std::cout << std::string(pad, ' ') << DIM << GRAY << desc << RESET;
    }
    std::cout << "\n";
}

void printMenuFooter()
{
    std::cout << "  " << BLUE << "└" << std::string(56, '-') << "┘" << RESET << "\n";
}

void printPrompt(const std::string& text = "Wybierz opcję")
{
    std::cout << "\n  " << GREEN << "❯ " << BOLD << text << ": " << RESET;
}

// ============================================================
//                     MENU GŁÓWNE
// ============================================================
void printMainMenu()
{
    printMenuBox("MENU GŁÓWNE");
    printMenuItem("1", "Pokaż pinout",       "Wyświetl mapę pinów płytki");
    printMenuItem("2", "Zmień pull",          "Ustaw rezystor PULL UP/DOWN");
    printMenuItem("3", "Przełącz stan pinu",  "Ustaw HIGH / LOW");
    printMenuItem("4", "Zmień tryb pinu",     "Ustaw INPUT / OUTPUT");
    printMenuItem("5", "Funkcja alternatywna","Wybierz tryb pracy pinu");
    std::cout << "  " << BLUE << "│" << RESET << "\n";
    printMenuItem("0", "Wyjdź",               "Zakończ program");
    printMenuFooter();
}

int readChoice()
{
    int choice;
    if (std::cin >> choice)
    {
        flushInput();
        return choice;
    }
    flushInput();
    return -1;
}

// ============================================================
//               NAGŁÓWKI DLA PODSTRON
// ============================================================
void printSectionTitle(const std::string& icon, const std::string& title)
{
    std::cout << "\n  " << BG_BLUE << "  " << icon << "  " << title << "  " << RESET << "\n\n";
}

} // namespace

// ============================================================
//                         MAIN
// ============================================================
int main()
{
    Raspberry rpi("4B");
    bool running = true;

    while (running)
    {
        clearScreen();
        printHeader("4B");
        printMainMenu();
        printPrompt();

        int choice = readChoice();

        switch (choice)
        {
            case 0:
                running = false;
                continue;

            case 1:
                clearScreen();
                printHeader("4B", "Pokaż pinout");
                printSectionTitle("📌", "PINOUT PŁYTKI");
                rpi.displayPins();
                pauseScreen();
                break;

            case 2:
                clearScreen();
                printHeader("4B", "Zmień PULL");
                printSectionTitle("⚡", "USTAWIENIA REZYSTORA PULL");
                rpi.changePull();
                pauseScreen();
                break;

            case 3:
                clearScreen();
                printHeader("4B", "Przełącz pin");
                printSectionTitle("🔌", "PRZEŁĄCZANIE STANU PINU");
                rpi.togglePin();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                printHeader("4B", "Zmień tryb pinu");
                printSectionTitle("🔄", "ZMIANA KIERUNKU PINU");
                rpi.changePinMode();
                pauseScreen();
                break;

            case 5:
                clearScreen();
                printHeader("4B", "Funkcja alternatywna");
                printSectionTitle("⚙", "FUNKCJE ALTERNATYWNE (ALT)");
                rpi.selectAlternateFunction();
                pauseScreen();
                break;

            default:
                showNotification("Nieprawidłowa opcja! Wybierz numer z menu.", "error");
                pauseScreen();
                break;
        }
    }

    // ============================================================
    //                    EKRAN POŻEGNALNY
    // ============================================================
    clearScreen();
    std::cout << "\n\n";
    std::cout << "  " << CYAN << BOLD;
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║                                          ║\n";
    std::cout << "  ║        Dziękuję za skorzystanie!         ║\n";
    std::cout << "  ║                                          ║\n";
    std::cout << "  ║       Do zobaczenia następnym razem      ║\n";
    std::cout << "  ║                                          ║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n";
    std::cout << RESET << "\n";
    return 0;
}
