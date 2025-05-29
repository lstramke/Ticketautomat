//KLASSE_Geldliste.hpp, Headerdatei für die Klasse Geldliste
#pragma once

#include "KLASSE_Geld.hpp"
#include <vector>

/** @brief Die Klasse Geldliste die zur Vwerwaltung des Geldes innerhalb des Automatens.
* 
* Diese Klasse enthält einen Vektor welcher Objekte der Geld Klasse enthält.
* Die Klasse stellt die Methode `addGeld`,`erhöheSorte`, `senkeSorte` und `ausgabeListe` zur Verfügung, 
* um die Geld-Objekte verwalten zu können.
*
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der geldlisten.cpp Datei
*/
class Geldliste{
    private:
        std::vector<Geld> geldliste;
    public:
        Geldliste();
        Geldliste(const Geldliste&);
        ~Geldliste();

        void addGeld(const Geld& geld);
        void erhöheSorte(unsigned int);
        bool senkeSorte(unsigned int);
        void ausgabeListe();
};
