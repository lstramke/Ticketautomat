
#pragma once

#include "KLASSE_Straßenbahn.hpp"
#include "KLASSE_Straßenbahnliste.hpp"
#include "KLASSE_Geld.hpp"
#include "KLASSE_Geldliste.hpp"
#include "KLASSE_Ticket.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <limits>

/**
* @brief Die Klasse Menue stellt Funktionen für Menü- und Benutzereingabeverarbeitung bereit.
* 
* Diese Utility-Klasse bietet Methoden zum Initialisieren von Geld, Auswählen und Kontrollieren von 
* Eingaben sowie zur Ausgabe von Menüs und Tickets. Sie interagiert mit den Klassen Geldliste und Straßenbahnliste.
* 
* Die Klasse enthält statische Methoden, um Menüaktionen zu verarbeiten und mit Benutzereingaben das Straßenbahn-Ticketsystem zu steuern.
*
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der menue.cpp Datei
*/
class Menue{

    public:
        
        //Initalisierungsfunktion

        static Geldliste initGeld(Geldliste&);

        //Auswahl- und Kontrollfunktionen

        static bool valid_haltestelle(const std::string&, Straßenbahnliste&);

        static bool straßenbahnAuswahl(std::string, Straßenbahnliste&);
        static unsigned int startAbfrage();
        static unsigned int geldEingabe(Geldliste&);
        static int wechselgeldBehandlung(unsigned long int, unsigned long int, Geldliste&);

        //Menüausgabefunktionen

        static void startMenue();
        static bool endMenue();
        static std::string straßenbahnMenue();
        static std::string starthaltestellenMenue(Straßenbahnliste&);
        static std::string endhaltestellenMenue(Straßenbahnliste&, const std::string&);
        static void bezahlMenue(std::string, std::string, Straßenbahnliste&, Geldliste&);

        static void fahrplanAnzeigen(Straßenbahnliste&);
        static void wechselgeldAusgabe(const std::vector<unsigned int>&, int, Geldliste&);         //nur Ausgabefunktion
        static void ticketAusgabe(std::string, std::string, std::string, unsigned long int, std::vector<unsigned int>, Geldliste&);       //nur Ausgabefunktion

        static void clear();
};
