//geldliste.cpp, enthält die Implementierungen der Funktionen der Klasse Geldliste

#include "../header/KLASSE_Geldliste.hpp"
#include "../header/KLASSE_Geld.hpp"

#include <vector>
#include <iostream>

//Hilfsfunktion

unsigned int sorteZuIndex(unsigned int);

/**
 * @brief Standart-Konstruktor der Geldlisten Klasse
*/
Geldliste::Geldliste(){}

Geldliste::Geldliste(const Geldliste& other){
    geldliste = other.geldliste;
}

/**
 * @brief Destruktor der Geldlisten Klasse
*/
Geldliste::~Geldliste(){}

/**
* @brief Fügt Geld zur Geldliste hinzu.
* 
* Diese Methode fügt ein Geld-Objekt zur Geldliste hinzu.
*
* @param geld Ein Geld-Objekt, das zur Geldliste hinzugefügt werden soll.
*/
void Geldliste::addGeld(const Geld& geld){
    geldliste.push_back(geld);
}

/**
* @brief Gibt die Geldliste aus.
* 
* Diese Methode durchläuft die Geldliste und gibt für jedes Geld-Objekt
* die Sorte gefolgt von der Anzahl auf der Konsole aus (mithilfe der get-Funktionen der Geld-Klasse).
*/
void Geldliste::ausgabeListe(){
    for(Geld& geld : geldliste){
        std::cout << geld.getSorte() << " " << geld.getAnzahl() <<std::endl;
    }
}

/**
* @brief Erhöht die Anzahl einer bestimmten Geldsorte in der Geldliste.
* 
* Diese Methode erhöht die Anzahl des Geld-Objekts für die angegebene Sorte um 1.
* Der Index der Sorte wird durch die Funktion `sorteZuIndex` ermittelt.
*
* @param sorte Ein unsigned int, der die Sorte des Geldes repräsentiert.
* @note es wird dabei getestet ob die Sorte einem Index zugeordnet werden kann 
* und wenn nicht wird ein std::out_of_range abgefangen und eine Fehlermeldung ausgegeben
*/
void Geldliste::erhöheSorte(unsigned int sorte){
    try{
        unsigned int index = sorteZuIndex(sorte);
        geldliste.at(index).erhoeheAnzahl();
    }catch(const std::out_of_range& e){
        std::cerr << "Fehler: " << e.what() << std::endl;
    }
}

/**
* @brief Verringert die Anzahl einer bestimmten Geldsorte in der Geldliste.
* 
* Diese Methode verringert die Anzahl des Geld-Objekts für die angegebene Sorte um 1.
* Der Index der Sorte wird durch die Funktion `sorteZuIndex` ermittelt.
*
* @param sorte Ein unsigned int, der die Sorte des Geldes repräsentiert.
* @return true, wenn die Anzahl erfolgreich verringert wurde, andernfalls false.
* @note Die funktion gibt den boolschen wert der `senkeAnzahl` Funktion der Geld-Klasse weiter.
* Es wird dabei getestet ob die Sorte einem Index zugeordnet werden kann 
* und wenn nicht wird ein std::out_of_range abgefangen und eine Fehlermeldung ausgegeben
*/
bool Geldliste::senkeSorte(unsigned int sorte){
    try{
        unsigned int index = sorteZuIndex(sorte);
        return geldliste.at(index).senkeAnzahl();
    }catch(const std::out_of_range& e){
        std::cerr << "Fehler: " << e.what() << std::endl;
        return false;
    }
}

/**
* @brief Ermittelt den Index einer Geldsorte in der Geldliste.
* 
* Diese Funktion gibt den Index für die angegebene Sorte zurück. 
* Die Zuordnung erfolgt sorte -> index, mit bspw. 17 -> 0.
* Falls 'sorte' nicht einem der erwarteten Werte entspricht, wird eine std::out_of_range-Ausnahme mit der Meldung
* "Sorte nicht gefunden" ausgelöst.

* @param sorte Ein unsigned int, der die Sorte des Geldes repräsentiert.
* 
* @return Der Index der Geldsorte in der Geldliste. 
* @throws std::out_of_range, wenn keine Zuordnung stattfinden konnte
*/
unsigned int sorteZuIndex(unsigned int sorte){
    unsigned int i = 0;
    switch (sorte)
    {
    case 17: return i; 
    case 11: return i +1; 
    case  7: return i +2; 
    case  5: return i +3; 
    case  3: return i +4; 
    case  2: return i +5; 
    case  1: return i +6; 
    default: throw std::out_of_range("Sorte nicht gefunden");
    }
}
