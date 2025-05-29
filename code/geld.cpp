//Geld.cpp, enthält die Implementierungen der Funktionen der Klasse Geld
#include "../header/KLASSE_Geld.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
* @brief Konstruktor der Geld-Klasse.
* 
* Initialisiert ein Geld-Objekt mit den angegebenen Parametern.
*
* @param s Ein String, der die Sorte des Geldes repräsentiert.
* @param a Ein unsigned int, der die Anzahl der Geldesorte repräsentiert.
*/
Geld::Geld(std::string s, unsigned long int a){
    sorte = s;
    anzahl = a;
}

/**
* @brief Destruktor der Geld-Klasse.
* 
* Wird aufgerufen wenn ein Objekt der Geld-Klasse zerstört wird.
*/
Geld::~Geld(){}

/**
* @brief Kopierkonstruktor der Geld-Klasse.
* 
* Erstellt ein neues Geld-Objekt durch Kopieren der Werte eines vorhandenen 
* Geld-Objekts.
*
* @param other Das zu kopierende Geld-Objekt.
*/
Geld::Geld(const Geld& other){
    sorte = other.sorte;
    anzahl = other.anzahl;
}

/**
* @brief Überladener Zuweisungsoperator für die Geld-Klasse.
* 
* Dieser Operator ermöglicht das Zuweisen eines Geld-Objekts an ein anderes Geld-Objekt.
* Dabei werden die Sorte und die Anzahl der Geldstücke von einem Geld-Objekt auf das andere kopiert.
* 
* @param other Das Geld-Objekt, von dem die Daten zugewiesen werden sollen.
* @return Eine Referenz auf das aktuelle Geld-Objekt nach der Zuweisung.
*/
Geld& Geld::operator=(const Geld& other){
    if(this != &other){
        sorte = other.sorte;
        anzahl = other.anzahl;
    }
    return *this;
}

/**
* @brief Erhöht die Anzahl des Geldes.
* 
* Diese Methode erhöht die Anzahl des Geld-Objekts um 1.
*/
void Geld::erhoeheAnzahl(){
    anzahl++;
}

/**
* @brief Reduziert die Anzahl des Geldes um 1, wenn diese größer als 0 ist.
*
* Diese Methode verringert die Anzahl des Geldes um 1, wenn die aktuelle Anzahl größer als 0 ist.
*
* @return True, wenn die Anzahl erfolgreich verringert wurde; False, wenn die Anzahl bereits 0 war und nicht weiter verringert werden konnte.
*/
bool Geld::senkeAnzahl(){
    if(anzahl > 0){
        anzahl--;
        return true;
    }
    else{
        return false;
    }
}

/**
* @brief Gibt Informationen über das Geld aus.
* 
* Diese Methode gibt die Sorte und die Anzahl des Geldes auf der Konsole aus.
*/
void Geld::ausgabe(){
    std::cout << sorte << " " << anzahl <<std::endl;
}

/**
* @brief Gibt die Sorte des Geldes zurück.
*
* Get-Funktion für die Sorte eines Objekts der Geld-Klasse
* 
* @return Ein String, der die Sorte des Geldes repräsentiert.
*/
std::string Geld::getSorte() {
    return sorte;
}

/**
* @brief Gibt die Anzahl des Geldes zurück.
* 
* Get-Funktion für die Anzahl eines Objekts der Geld-Klasse
*
* @return Ein unsigned int, der die Anzahl des Geldes repräsentiert.
*/
unsigned long int Geld::getAnzahl() {
    return anzahl;
}
