//KLASSE_Straßenbahn.hpp, Headerdatei zur Klasse Straßenbahn
#pragma once
#include <string>
#include <vector>
#include <iostream>

/**
* @brief Die Klasse Straßenbahn dient der Speicherung der Straßenbahnlinien mit ihren Daten
*
* Diese Klasse enthält die Daten `linienname`, `preisProHaltestelle` 
* und eine Liste der Haltestellen im Vektor `haltestellen` privat gekapselt.
* Die Klasse stellt die Methode `berechneEntfernungZWHaltestellen` 
* sowie eine get-Methode für jeden Datenwert zur Verfügung.
*
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der straßenbahn.cpp Datei
*/
class Straßenbahn{
    private:

        std::string linienname;
        unsigned long int preisProHaltestelle;
        std::vector<std::string> haltestellen;
        
    public:

        Straßenbahn(std::string, unsigned long int, std::vector<std::string>);
        Straßenbahn(const Straßenbahn&);
        ~Straßenbahn();
        
        std::string getLinienname();
        unsigned long int getPreisProHaltestelle();
        std::vector<std::string> getHaltestellen();

        unsigned int berechneEntfernungZwHaltestellen(std::string, std::string);
};
