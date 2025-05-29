// KLASSE_Straßenbahnliste.hpp, Headerdatei zur Klasse Straßenbahnliste
#pragma once

#include "KLASSE_Straßenbahn.hpp"
#include <vector>
#include <string>

/**
* @brief Die Klasse Straßenbahnliste dient der Verwaltung der Straßenbahnlinien
*
* Diese Klasse enthält einen Vektor welcher Objekte der Straßenbahn Klasse enthält.
* Die Klasse stellt die Methode `addStraßenbahn`, `ausgabeFahrplan` und `straßenbahnAnStelle` zur Verfügung, 
* um die Straßenbahnen verwalten zu können.
*
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der straßenbahnlisten.cpp Datei
*/
class Straßenbahnliste{
    private:
        std::vector<Straßenbahn> straßenbahnliste;
    public:
        Straßenbahnliste();
        ~Straßenbahnliste();

        void addStraßenbahn(const Straßenbahn&);
        void ausgabeFahrplan();
        Straßenbahn straßenbahnAnStelle(unsigned int);
};
