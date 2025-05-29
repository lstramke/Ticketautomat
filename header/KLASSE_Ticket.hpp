// KLASSE_Ticket.hpp, Headerdatei der Klasse Ticket
#pragma once
#include <string>
#include <ctime>

/**
* @brief Die Klasse Ticket dient der Erstellung von einheitlichen Tickets.
* 
* Die Klasse enthält die Daten `austellungdatum`,`ticketnummer` und `automatennummer` privat gekapselt.
* Die KLasse stellt die Methoden `ausgabeTicket` und `speichernTicket` zur Verfügung.
* 
* @note Beschreibungen zu den Methoden sowie deren Implementierung in der ticket.cpp Datei
*/
class Ticket{
    private:
        std::tm* austellungsdatum;
        unsigned int ticketnummer;
        unsigned int automatennummer;
    public:
        Ticket();
        ~Ticket();

        void ausgabeTicket(std::string&, std::string&, std::string&, unsigned long int&);
        void speichernTicket(std::string&, std::string& , std::string&, unsigned long int&);
        

};
