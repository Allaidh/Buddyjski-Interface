Konsolowy menedżer GPIO złącza J8
Termin: 25 września 2026 12:05
•
Dozwolone jest wiele przesłanych zadań
•
Kończy się 25 września 2026 12:10
Instrukcje
Zaimplementuj aplikację konsolową (CLI) do odczytu stanu i sterowania pinami GPIO na złączu J8 minikomputera Raspberry Pi zgodnie z zasadami programowania obiektowego w języku C++.

Wymagania:
Aplikacja udostępnia interfejs tekstowy (menu) umożliwiający wykonanie następujących operacji:

Wybór pinu:  Wskazanie pinu na złączu J8 poprzez numer fizyczny (numeracja złącza J8) lub numer logiczny BCM.
Konfiguracja funkcji pinu: Ustawienie funkcji pinu jako GPIO (wejście lub wyjście) albo wybór jednej z dostępnych funkcji alternatywnych (aplikacja prezentuje nazwę funkcji przypisaną do wybranego pinu). 
Konfiguracja rezystorów wewnętrznych i stanu wyjścia: Ustawienie rezystorów podciągających. Dla pinów skonfigurowanych jako wyjście możliwość ustawienia stanu logicznego. 
Odczyt i prezentacja aktualnej konfiguracji pinu. Wyświetlenie aktualnych parametrów wybranego pinu, w szczególności:
numeru fizycznego i numeru BCM,
aktualnie ustawionej funkcji (GPIO lub funkcja alternatywna),
kierunku pracy (wejście/wyjście) dla funkcji GPIO,
konfiguracji rezystorów wewnętrznych (pull-up, pull-down, wyłączony),
aktualnego stanu logicznego (wysoki/niski).

Kryteria oceny:
Poprawność zamodelowania problemu z wykorzystaniem co najmniej jednej klasy opisującej złącze J8 oraz jego piny GPIO zgodnie z wymaganiami. (1 pkt)
Stabilność i ergonomia interfejsu tekstowego (czytelne menu, zabezpieczenie przed niedozwolonymi operacjami na pinach). (1 pkt)
Czystość kodu (zgodność ze standardem C++, znaczące nazewnictwo, podział na pliki nagłówkowe i źródłowe). (1 pkt)
Dołączony plik budowania (Makefile). (1 pkt)

**UWAGA: Każdy z członków grupy przesyła ten samo kod. Archiwum tar.bz2 należy przesłać do sprawdzenia przed wystąpieniem.**

Ocena:
niedostateczna - 0 pkt.
dopuszczająca - 1 pkt
dostateczna - 2 pkt.
dobra - 3 pkt.
bardzo dobra - 4 pkt
