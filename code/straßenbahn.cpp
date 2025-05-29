//Straßenbahn.cpp, enthält die Implementierung der Funktionen der Klasse Straßenbahn
#include <string>
#include <vector>

#include "../header/KLASSE_Straßenbahn.hpp"

/**
* @brief Konstruktor der Straßenbahn-Klasse.
*
* Der Konstruktor initialisiert eine Straßenbahn mit den angegebenen Parametern.
*
* @param n Der Name der Straßenbahnlinie.
* @param p Der Preis pro Haltestelle der Straßenbahnlinie.
* @param h Die Liste der Haltestellen der Straßenbahnlinie.
*/
Straßenbahn::Straßenbahn( std::string n , unsigned long int p, std::vector<std::string> h ){
    linienname = n;
    preisProHaltestelle = p;
    haltestellen = h;
}

/**
* @brief Kopierkonstruktor der Straßenbahn-Klasse.
*
* Der Kopierkonstruktor erstellt eine Kopie einer vorhandenen Straßenbahn.
*
* @param other Das Straßenbahn-Objekt, von dem eine Kopie erstellt werden soll.
*/
Straßenbahn::Straßenbahn(const Straßenbahn& other){
    linienname = other.linienname;
    preisProHaltestelle = other.preisProHaltestelle;
    haltestellen = other.haltestellen;
}

//Destruktur der Straßenbahn Klasse
Straßenbahn::~Straßenbahn(){}

/**
* @brief Berechnet die Anzahl der Haltestellen zwischen zwei gegebenen Haltestellen.
*
* Diese Methode nimmt die Namen der Start- und Endhaltestellen und berechnet die Anzahl der Haltestellen
* zwischen ihnen auf der Straßenbahnlinie. Die Berechnung erfolgt basierend auf den Indizes der Haltestellen
* im Vektor `haltestellen`.
*
* @param start Der Name der Starthaltestelle.
* @param end Der Name der Endhaltestelle.
* @return Die Anzahl der Haltestellen zwischen Start- und Endhaltestelle.
*         Falls eine der Haltestellen nicht gefunden wird, wird 0 zurückgegeben.
*/
unsigned int Straßenbahn::berechneEntfernungZwHaltestellen(std::string start, std::string end){
    unsigned int indexStart = 1000;
    unsigned int indexEnd = 1000;
    for(unsigned int i =0; i< haltestellen.size(); i++){
        if(start == haltestellen.at(i)){
            indexStart = i;          
        }
        if(end == haltestellen.at(i)){
            indexEnd = i;
        }
    }
    if(indexStart != 1000 && indexEnd != 1000){
        if(indexStart > indexEnd){ return indexStart - indexEnd; }
        else{ return indexEnd -indexStart; }
    }
    else{ return 0; }
}

//Get-Funktionen

/**
* @brief Gibt den Namen der Straßenbahnlinie zurück.
*
* @return Der Name der Straßenbahnlinie als Zeichenkette.
*/
std::string Straßenbahn::getLinienname(){
    return linienname;
}

/**
* @brief Gibt den Preis pro Haltestelle zurück.
*
* @return Der Preis pro Haltestelle als unsigned long int.
*/
unsigned long int Straßenbahn::getPreisProHaltestelle(){
    return preisProHaltestelle;
}

/**
* @brief Gibt die Liste der Haltestellen für die Straßenbahnlinie zurück.
*
* @return Ein Vektor von Zeichenketten, der die Namen der Haltestellen enthält.
*/
std::vector<std::string> Straßenbahn::getHaltestellen(){
    return haltestellen;
}
