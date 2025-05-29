//KLASSE_Geld.hpp, Headerdatei zur Klasse Geld
#pragma once

#include <vector>
#include <string>

/** @brief Die Klasse Geld ist zur Speicherung Geldes innerhalb des Automatens mit den dazugehörigen Daten.
* 
* Die Klasse enthält die Daten `sorte` ud `anzahl` privat gekapselt.
* Die Klasse stelt die Methoden `erhöheAnzahl`, `senkeAnzahl`, `ausgabe` und 
* eine get-Methode für beide Daten bereit
*
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der geld.cpp Datei
*/
class Geld{
    private:
        std::string sorte;
        unsigned long int anzahl;
        
    public:
        Geld(std::string, unsigned long int);
        ~Geld();
        Geld(const Geld&);                      // Kopieroperator
        Geld& operator=(const Geld&);           // Zuweisungsoperator

        void erhoeheAnzahl();
        bool senkeAnzahl();
        void ausgabe();
        
        std::string getSorte();
        unsigned long int getAnzahl();
};
