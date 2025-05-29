// straßenbahnliste.cpp, enthält die Implementierungen zu den Funktionen der Straßenbahnlisten Klasse

#include "../header/KLASSE_Straßenbahnliste.hpp"

/**
 * @brief Standart-Konstruktor der Straßenbahnlisten Klasse
*/
Straßenbahnliste::Straßenbahnliste(){}

/**
 * @brief Destruktor der Straßenbahnlisten Klasse
*/
Straßenbahnliste::~Straßenbahnliste(){}

/**
* @brief Fügt eine Straßenbahn der Straßenbahnliste hinzu.
* 
* Fügt eine übergebene Straßenbahn der Liste der Straßenbahnen hinzu.
* 
* @param straßenbahn Die Straßenbahn, die zur Liste hinzugefügt werden soll.
*/
void Straßenbahnliste::addStraßenbahn(const Straßenbahn& straßenbahn){
    straßenbahnliste.push_back(straßenbahn);
}

/**
* @brief Gibt den Fahrplan für die erste Straßenbahn in der Liste aus.
* 
* Die Funktion überprüft, ob die Straßenbahnliste nicht leer ist.
* Wenn die Liste leer ist, wird eine Meldung ausgegeben und die Funktion beendet.
* Andernfalls werden der Liniennamen und die Haltestellen der ersten Straßenbahn in der Liste
* auf der Konsole ausgegeben.
*
* @note Es sollte immer nur eine Straßenbahn in der Liste liegen
*/
void Straßenbahnliste::ausgabeFahrplan(){
    if(straßenbahnliste.empty()){
        std::cerr << "Fehler (Straßebahnliste::ausgabeFahrplan): Es ist keine Straßenbahn in der Liste" <<std::endl;
        return;
    }
    const std::vector<std::string>& haltestellen = straßenbahnliste.at(0).getHaltestellen();
    std::cout   << straßenbahnliste.at(0).getLinienname()
                << ":" << std::endl;
    for(unsigned int i = 0; i < haltestellen.size() ; i++ ){
        std::cout << haltestellen.at(i) <<std::endl;
    }
    std::cout << std::endl;
}

/**
* @brief Gibt die Straßenbahn an der angegebenen Position zurück.
*
* Die Funktion überprüft, ob die angegebene Position innerhalb des gültigen Bereichs der Straßenbahnliste liegt.
* Wenn ja, wird die Straßenbahn an der Position zurückgegeben, andernfalls wird eine "ungültige" Straßenbahn
* mit dem Namen "ungültig", einem Preis von 0 und einer leeren Haltestellenliste erstellt und zurückgegeben.
*
* @param i Die Position der gesuchten Straßenbahn in der Straßenbahnliste.
* @return Die Straßenbahn an der angegebenen Position oder eine "ungültige" Straßenbahn, wenn die Position ungültig ist.
*/
Straßenbahn Straßenbahnliste::straßenbahnAnStelle(unsigned int i){
    if( i < straßenbahnliste.size()){
        return straßenbahnliste.at(i);
    }
    else{
        return Straßenbahn("ungültig", 0, {});
    }
}
