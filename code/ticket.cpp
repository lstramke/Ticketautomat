// ticket.cpp, enthält die Implementierungen der Funktionen der Klasse Ticket

#include "../header/KLASSE_Ticket.hpp"

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

//automatisches Hochzählen er Ticketnummer
static unsigned int t_counter = 1;

/**
* @brief Konstruktor der Ticket-Klasse.
* 
* Initialisiert ein Ticket-Objekt mit einer eindeutigen Ticketnummer, 
* dem aktuellen Austellungsdatum, und einer Automatennummer. 
* Wenn es ein Probelem bei der Zeitbestimmung gibt wird ein runtime_error geworfen.
*
* @throws std::runtime_error, falls ein Fehler beim Initialisieren des Austellungsdatums auftritt.
* @note die Ticketnummer wird bei jedem Konstruktor aufruf um 1 erhöht
*/
Ticket::Ticket(){
    std::time_t t = std::time(nullptr);
    unsigned int a_num = 1;
    ticketnummer = t_counter;
    t_counter++;
    automatennummer = a_num;
    if(std::tm* localTime = std::localtime(&t)){
            austellungsdatum = localTime;
    }
    else{
        throw std::runtime_error("Fehler beim Initalisieren des Austellungsdatums");
    }
}

/**
 * @brief Destruktor der Ticket Klasse
*/
Ticket::~Ticket(){}

/**
* @brief Gibt die Ticketinformationen auf der Konsole aus.
* 
* Die Funktion gibt die Ticketinformationen, einschließlich Start- und Endhaltestelle, 
* Preis, Ticketnummer, Automatennummer und Ausstellungsdatum, auf der Konsole aus.
*
* @param start Die Start-Haltestelle des Tickets.
* @param end Die End-Haltestelle des Tickets.
* @param preis Der Preis des Tickets.
*/
void Ticket::ausgabeTicket(std::string& linie, std::string& start, std::string& end, unsigned long int& preis){
    std::cout   <<std::endl
                << "Entnehmen Sie ihr Ticket"
                <<std::endl
                << "___________________________________________________" <<std::endl
                << "| Ticket der LV" <<std::endl
                << "| Für: " << linie <<std::endl
                << "| Starthaltestelle: " << start <<std::endl
                << "| Endhaltestelle: " << end << std::endl
                << "| Preis: " << preis << "GE" <<std::endl
                << "| " <<std::endl
                << "| " << ticketnummer << "            " << automatennummer << "           " 
                << (austellungsdatum->tm_year + 1900) <<(austellungsdatum->tm_mon + 1) << (austellungsdatum->tm_mday) << (austellungsdatum->tm_hour) << (austellungsdatum->tm_min) << "-" << (austellungsdatum->tm_sec)<<std::endl
                << "---------------------------------------------------" << std::endl;
}

/**
* @brief Speichert die Ticketinformationen in einer Log-Datei.
* 
* Diese Methode öffnet die Log-Datei "Ticket_log/verkaufte_Tickets.txt" im Anhänge-Modus und
* schreibt die Ticketinformationen, einschließlich Ticketnummer, Automatennummer, Ausstellungsdatum,
* Linie, Start- und Endhaltestelle sowie Preis, in die Datei.
* 
* @param linie Die Linie des Tickets.
* @param start Die Start-Haltestelle des Tickets.
* @param end Die End-Haltestelle des Tickets.
* @param preis Der Preis des Tickets.
* @note Die Funktion geht davon aus das der Pfad korrekt ist, 
* wenn die Datei nicht geöffnet werden kann wird eine Fehlermeldung ausgegeben und nichts geschrieben.
*/
void Ticket::speichernTicket(std::string& linie, std::string& start, std::string& end, unsigned long int& preis){
    std::string pfad = "Logs/verkaufte_Tickets.txt";
    std::ofstream ticketLog(pfad, std::ios::app);
    if(!ticketLog.is_open()){
        std::cerr << "Fehler (Ticket::speichernTicket): Die Log-Datei konnte nicht geöffnet werden." << std::endl;
        return;
    }
    ticketLog   << ticketnummer << ", " 
                << automatennummer << ", " 
                << (austellungsdatum->tm_year + 1900) << "-" <<(austellungsdatum->tm_mon + 1) << "-" << (austellungsdatum->tm_mday) << "-" << (austellungsdatum->tm_hour) << "-" << (austellungsdatum->tm_min) << "-" << (austellungsdatum->tm_sec) << ", "
                << linie << ", " << start << ", " << end << ", " << preis <<std::endl;
}
