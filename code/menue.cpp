//menü.cpp Funktionen für die Menüführung

#include "../header/KLASSE_Menue.hpp"

#include <iostream>
#include <vector>
#include <string>

// aus einlesen.cpp

std::vector<std::string> read_data_Straßenbahnlinie(std::string);
std::vector<std::string> read_data_Haltestellen(std::string);
std::vector<std::string> read_init_Geldscheine();

/**
* @brief Initialisiert die Geldliste basierend auf den Werten aus der Datei "Init_Geldscheine".
* 
* Diese Methode liest die Werte für die Geldscheine aus der Datei "Init_Geldscheine" und initialisiert damit eine Geldliste.
* Die Methode erstellt für jeden Geldschein ein entsprechendes Geld-Objekt und fügt es der Geldliste hinzu.
* 
* @param geldliste Die Geldliste, die initialisiert werden soll.
* @return Die initialisierte Geldliste.
*/
Geldliste Menue::initGeld(Geldliste& geldliste){
    std::vector<std::string> initGeld = read_init_Geldscheine();
    for(unsigned int k=0; k < initGeld.size()-1; k+=2){
        geldliste.addGeld(Geld(initGeld.at(k), std::stoul(initGeld.at(k+1))));   
    }
    return geldliste;
}

/**
* @brief Prüft ob die eingegebene Haltestelle existiert.
* 
* Die Funktion testet für jedes Element im Vektor Haltestellen, ob die eingegebene 
* Haltestelle existiert. Wenn sie gefunden wird, wird true zurückgegeben, andernfalls false.
* 
* @param haltestelle Die vom Benutzer eingegebene Haltestelle, die überprüft werden soll.
* @param straßenbahnliste Die Liste enthält die Straßenbahn, in der nach der Haltestelle gesucht wird,
* siehe `class Straßenbahnliste`
* @return true, wenn die Haltestelle vorhanden ist, false, wenn nicht.
*/
bool Menue::valid_haltestelle(const std::string& haltestelle, Straßenbahnliste& straßenbahnliste){
    for(unsigned int i =0; i< straßenbahnliste.straßenbahnAnStelle(0).getHaltestellen().size(); i++){
        if(haltestelle == straßenbahnliste.straßenbahnAnStelle(0).getHaltestellen().at(i)){
            return true;      
        }
    }
    return false;
}

/**
* @brief Leert den Eingabepuffer des Konsolen-Streams.
* 
* Diese Methode löscht den Eingabepuffer des Konsolen-Streams, um unerwünschte Eingaben zu verwerfen und den Stream zu bereinigen.
* Sie wird verwendet, um sicherzustellen, dass nach der Eingabeaufforderung keine unerwarteten Eingaben das Programm beeinflussen.
*/
void Menue::clear(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
* @brief Fragt den Benutzer nach einer Startauswahl und gibt die eingegebene Option zurück.
* 
* Diese Methode fordert den Benutzer auf, eine Option für den Start des Programms einzugeben, entweder 1 für den Ticketkauf oder 2 für das Beenden des Programms.
* Sie liest die Eingabe des Benutzers ein und überprüft, ob sie entweder 1 oder 2 ist.
* Wenn die Eingabe gültig ist, wird sie zurückgegeben. Andernfalls wird der Benutzer erneut aufgefordert, eine gültige Eingabe zu tätigen.
* Nach der Eingabe wird der Eingabepuffer des Konsolen-Streams geleert, um unerwünschte Eingaben zu verwerfen und den Stream zu bereinigen.
* 
* @return Die vom Benutzer eingegebene Option für den Start des Programms (1 für Ticketkauf, 2 für Beenden).
*/
unsigned int Menue::startAbfrage(){
    unsigned int Eingabe;
    while(true){
        std::cout << "Eingabe: ";
        std::cin >> Eingabe;
        if(Eingabe == 1 || Eingabe == 2){
            Menue::clear();
            return Eingabe;
        }
        else{
            Menue::clear();
            std::cout << "Bitte 1 für Ticketerwerb, 2 für Beenden eingeben" << std::endl;
        }
    }
}

/**
* @brief Zeigt das Startmenü auf der Konsole an.
* 
* Diese Methode gibt das Startmenü auf der Konsole aus, das aus verschiedenen Optionen besteht:
* [1] Ticket kaufen und [2] Beenden.
*/
void Menue::startMenue(){
    std::cout   << std::endl
                << "---------- Willkommen ----------" << std::endl
                << "[1] Ticket kaufen" << std::endl
                << "[2] Beenden" << std::endl
                << std::endl;
}

/**
* @brief Zeigt das Endmenü auf der Konsole an und verarbeitet die Benutzereingabe.
* 
* Diese Methode zeigt das Endmenü auf der Konsole an, das die Optionen zum Beenden des Programms oder zum Zurückkehren zum Startmenü enthält.
* Benutzer werden aufgefordert, ihre Auswahl einzugeben, und die Methode gibt true zurück, wenn die Auswahl zum Beenden des Programms führt,
* andernfalls wird false zurückgegeben, um zum Startmenü zurückzukehren.
* 
* @return true, wenn das Programm beendet werden soll, andernfalls false.
*/
bool Menue::endMenue(){
    unsigned int Eingabe;
    std::cout   << std::endl
                << "---------- Beenden -------------" << std::endl
                << "Möchtest du das Programm wirklich beenden?" << std::endl
                << "[1] Ja" << std::endl
                << "[ ] Ansonsten Nein, zurück ins Startmenü" << std::endl
                << std::endl
                << "Eingabe: ";
    std::cin >> Eingabe;
    if(Eingabe == 1){
        std::cout << "Beendet" << std::endl;
        return true;
    } 
    else{
        Menue::clear();
        return false;
    }
}

/**
* @brief Zeigt das Menü zur Auswahl einer Straßenbahnlinie auf der Konsole an und fordert eine Benutzereingabe.
* 
* Diese Methode gibt das Menü zur Auswahl einer Straßenbahnlinie auf der Konsole aus und fordert den Benutzer auf, die Nummer der gewünschten Straßenbahn einzugeben.
* Nach der Eingabe wird der Eingabepuffer gelöscht, um keine Überträge für die nächste Eingabe zu haben.
* 
* @return Die eingegebene Nummer der gewünschten Straßenbahnlinie als Zeichenkette.
*
* @note Die Funktion geht davon aus, dass die Benutzereingabe korrekt ist, die Prüfung erfolgt erst in der `Menue::straßenbahnAuswahl()`
*/
std::string Menue::straßenbahnMenue(){
    std::string straßenbahnlinie;
    std::cout   << std::endl
                << "----- Straßenbahnauswahl -------" << std::endl
                << "Gib die Nummer der gewünschten Straßenbahn ein (bspw. 11): ";
    std::cin >> straßenbahnlinie;
    Menue::clear();
    return straßenbahnlinie;
}

/**
* @brief Zeigt den Fahrplan einer bestimmten Straßenbahnlinie auf der Konsole an.
* 
* Diese Methode gibt den Fahrplan einer bestimmten Straßenbahnlinie auf der Konsole aus,
* indem sie die Methode `Straßenbahnliste::ausgabeFahrplan()` aufruft, um den Fahrplan der übergebenen Straßenbahnliste anzuzeigen.
* Nach der Fahrplanausgabe wird eine Überschrift für die Haltestellenauswahl angezeigt.
* 
* @param straßenbahnliste Die Liste der Straßenbahnen, deren Fahrplan angezeigt werden soll.
*/
void Menue::fahrplanAnzeigen(Straßenbahnliste& straßenbahnliste){
    std::cout   << std::endl
                << "---------- Fahrplan ------------" <<std::endl;
    straßenbahnliste.ausgabeFahrplan();
    std::cout   << "----- Haltestellenauswahl ------" <<std::endl;
}

/**
 * @brief Ermöglicht die Auswahl einer Start-Haltestelle für eine bestimmte Straßenbahnlinie.
 * 
 * Diese Methode ermöglicht es dem Benutzer, den Namen einer Start-Haltestelle für eine bestimmte Straßenbahnlinie einzugeben.
 * Dabei wird mithlfe Menue::valid_halestelle überprüft, ob die eingegebene Haltestelle in der Liste der Haltestellen der übergebenen Straßenbahnliste vorhanden ist.
 * Wenn die eingegebene Haltestelle gültig ist, wird sie zurückgegeben. Andernfalls wird eine Fehlermeldung ausgegeben, 
 * und der Benutzer wird erneut aufgefordert, eine gültige Haltestelle einzugeben.
 * 
 * @param straßenbahnliste Die Liste der Straßenbahnen, für die eine Start-Haltestelle ausgewählt werden soll.
 * @return Der Name der ausgewählten Start-Haltestelle.
 */
std::string Menue::starthaltestellenMenue(Straßenbahnliste& straßenbahnliste){
    std::string starthaltestelle;
    while(true){
        std::cout   << std::endl
                    << "Starthaltestelle:" <<std::endl
                    << "Gib den Namen der Starthaltestelle ein: "; 
        std::getline(std::cin, starthaltestelle);
        if(Menue::valid_haltestelle(starthaltestelle, straßenbahnliste)){
            return starthaltestelle;
        }
        else{
            std::cout << "Ungültige Haltestelle, bitte Haltestelle wie im Fahrplan eingeben, auch Groß-Kleinschreibung." <<std::endl;
        }
    }
}

/**
* @brief Ermöglicht die Auswahl einer End-Haltestelle für eine bestimmte Straßenbahnlinie.
* 
* Diese Methode ermöglicht es dem Benutzer, den Namen einer End-Haltestelle für eine bestimmte Straßenbahnlinie einzugeben.
* Dabei wird überprüft, ob die eingegebene Haltestelle in der Liste der Haltestellen der übergebenen Straßenbahnliste vorhanden ist
* und ob sie sich von der Start-Haltestelle unterscheidet.
* Wenn die eingegebene Haltestelle gültig ist und sich von der Start-Haltestelle unterscheidet, wird sie zurückgegeben.
* Andernfalls wird eine Fehlermeldung ausgegeben, und der Benutzer wird erneut aufgefordert, eine gültige Haltestelle einzugeben.
* 
* @param straßenbahnliste Die Liste der Straßenbahnen, für die eine End-Haltestelle ausgewählt werden soll.
* @param start Der Name der Start-Haltestelle, von der die Fahrt beginnt.
* @return Der Name der ausgewählten End-Haltestelle.
*/
std::string Menue::endhaltestellenMenue(Straßenbahnliste& straßenbahnliste, const std::string& start){
    std::string endhaltestelle;
    while(true){
        std::cout   << std::endl
                    << "Endhaltestelle:" <<std::endl
                    << "Gib den Namen der Endhaltestelle ein: ";
        std::getline(std::cin, endhaltestelle);
        if(Menue::valid_haltestelle(endhaltestelle, straßenbahnliste) && endhaltestelle != start){
            return endhaltestelle;
        }
        else{
            std::cout   << "Ungültige Haltestelle, bitte Haltestelle wie im Fahrplan eingeben." << std::endl
                        << "Außerdem kann die Endhaltestelle nicht die Starthaltestelle sein." << std::endl;
        }
    }
}    

/**
* @brief Ermöglicht die Auswahl einer Straßenbahnlinie.
* 
* Diese Methode ermöglicht es dem Benutzer, eine Straßenbahnlinie anhand ihrer Nummer auszuwählen.
* Dabei werden die Daten der ausgewählten Straßenbahnlinie und ihrer Haltestellen aus externen Dateien eingelesen.
* Wenn die Daten erfolgreich eingelesen wurden, wird die Straßenbahnlinie zur übergebenen Straßenbahnliste hinzugefügt, und die Methode gibt true zurück.
* Andernfalls wird eine Fehlermeldung ausgegeben, und die Methode gibt false zurück.
* 
* @param liniennummer Die Nummer der ausgewählten Straßenbahnlinie als Zeichenkette.
* @param straßenbahnliste Die Liste der Straßenbahnen, zu der die ausgewählte Straßenbahnlinie hinzugefügt werden soll.
* @return true, wenn die Straßenbahnlinie erfolgreich ausgewählt und hinzugefügt wurde, ansonsten false.
*/
bool Menue::straßenbahnAuswahl(std::string liniennummer, Straßenbahnliste& straßenbahnliste){
    std::vector<std::string> dataStraßenbahnlinie = read_data_Straßenbahnlinie(liniennummer);
    std::vector<std::string> dataHaltestellen = read_data_Haltestellen(liniennummer);

    if(!dataStraßenbahnlinie.empty() && !dataHaltestellen.empty()){         //Überprüfung ob etwas eingelesen wurde
        straßenbahnliste.addStraßenbahn(Straßenbahn(dataStraßenbahnlinie.at(0), std::stoul(dataStraßenbahnlinie.at(1)), dataHaltestellen));
        return true;
    }
    else{
        std::cout << "Linie unbekannt" <<std::endl;
        return false;
    }
}

/**
* @brief Ermöglicht die Durchführung des Bezahlvorgangs für ein Straßenbahnticket.
* 
* Diese Methode führt den Bezahlvorgang für ein Straßenbahnticket durch. Zuerst wird der Preis des Tickets berechnet
* basierend auf der Entfernung zwischen Start- und Endhaltestelle sowie dem Preis pro Haltestelle der Straßenbahn.
* Dann wird der Benutzer aufgefordert, die Geldscheine einzeln einzugeben, um den Betrag zu bezahlen. 
* Der Benutzer kann den Vorgang jederzeit abbrechen, indem er 0 eingibt.
* Wenn der bezahlte Betrag den Preis des Tickets übersteigt, wird das Wechselgeld berechnet und ausgegeben.
* Am Ende wird das Ticket ausgegeben und der Bezahlvorgang als abgeschlossen markiert.
* 
* @param starthaltestelle Die Start-Haltestelle des Tickets.
* @param endhaltestelle Die End-Haltestelle des Tickets.
* @param straßenbahnliste Die Liste der verfügbaren Straßenbahnen.
* @param geldliste Die Liste der verfügbaren Geldscheine für den Bezahlvorgang.
*/
void Menue::bezahlMenue(std::string starthaltestelle, std::string endhaltestelle, Straßenbahnliste& straßenbahnliste, Geldliste& geldliste){
    unsigned long int preis = straßenbahnliste.straßenbahnAnStelle(0).berechneEntfernungZwHaltestellen(starthaltestelle, endhaltestelle) * straßenbahnliste.straßenbahnAnStelle(0).getPreisProHaltestelle();
    unsigned long int bezahlt = 0;
    std::vector<unsigned int> eingegebeneScheine;
    int abgeschlossenheit = 1;
    std::cout   << std::endl << "--------- Bezahlen ----------" << std::endl
                << "Der Preis beträgt: " << preis << " GE" << std::endl
                << "Automat akzeptiert GE-Schein 17, 11, 7, 5, 3, 2, 1" << std::endl
                << "Bitte gebe deine Scheine einzeln nacheinander ein." << std::endl
                << "Um den Vorgang abzubrechen gebe 0 ein." << std::endl;
    while(bezahlt < preis){
        unsigned int abbruch = 400;                                              // wie in geldEingabe                                            // wie in geldEingabe
        std::cout << "Noch zu bezahlen: " << preis - bezahlt << " | ";
        unsigned int eingegebenerSchein = Menue::geldEingabe(geldliste);
        if(eingegebenerSchein == abbruch){
            std::cout << std::endl << "-- Bezahlvorgang abgebrochen --" << std::endl;
            Menue::clear();
            Menue::wechselgeldAusgabe(eingegebeneScheine, 2, geldliste);
            return;
        }else{
            bezahlt += eingegebenerSchein;
            eingegebeneScheine.push_back(eingegebenerSchein);
        }
    }if(bezahlt > preis){
        abgeschlossenheit = Menue::wechselgeldBehandlung(preis, bezahlt, geldliste);
    }
    if(abgeschlossenheit == 1){             //passend bezahlt oder Wechselgeld konnte passend usgegeben werden           
        std::cout   << "- Bezahlvorgang abgeschlossen -" <<std::endl;
        Menue::ticketAusgabe(straßenbahnliste.straßenbahnAnStelle(0).getLinienname(), starthaltestelle, endhaltestelle, preis, eingegebeneScheine, geldliste);
    }else if(abgeschlossenheit == 2){        //Wechselgeld konnte nicht passend ausgegeben werden und der User wollte anders bezahlen
        Menue::wechselgeldAusgabe(eingegebeneScheine, 2, geldliste);
        Menue::bezahlMenue(starthaltestelle, endhaltestelle, straßenbahnliste, geldliste);
    }else{                                   //Wechselgeld konnte nicht passend ausgegeben werden und der User hat den Ticketkauf abgebrochen
        Menue::wechselgeldAusgabe(eingegebeneScheine, 2, geldliste);
    }
}

/**
* @brief Verarbeitet die Eingabe von Geldscheinen für den Bezahlvorgang.
* 
* Diese Methode erwartet die Eingabe eines Geldscheins durch den Benutzer und überprüft,
* ob die Eingabe gültig ist. Gültige Eingaben sind 17, 11, 7, 5, 3, 2 oder 1 GE-Scheine.
* Wenn die Eingabe gültig ist, wird der Geldschein zur Liste der verfügbaren Geldscheine hinzugefügt.
* Eine Eingabe von 0 signalisiert den Abbruch des Bezahlvorgangs.
* 
* @param geldliste Die Liste der verfügbaren Geldscheine.
* @return Die eingegebene Geldschein-Wert oder 0 im Falle einer ungültigen Eingabe oder 400 im Fall eines Abbruchs.
*/
unsigned int Menue::geldEingabe(Geldliste& geldliste){
    unsigned int Eingabe;
    std::cout << "Eingabe: ";
    if(!(std::cin >> Eingabe)){
        Menue::clear();
        std::cout << "Ungültige Eingabe, Bitte nur 17, 11, 7, 5, 3, 2, 1 GE-Scheine eingeben" <<std::endl;
        return 0;
    }
    if(Eingabe == 17 || Eingabe == 11 || Eingabe == 7 || Eingabe == 5 || Eingabe == 3 || Eingabe == 2 || Eingabe == 1 ){
        Menue::clear();
        geldliste.erhöheSorte(Eingabe);
        return Eingabe;
    }
    else if(Eingabe == 0){
        unsigned int abbruch = 400;                                      // wie in bezahlMenue
        return abbruch;
    }
    else{
        Menue::clear();
        std::cout << "Ungültige Eingabe, Bitte nur 17, 11, 7, 5, 3, 2, 1 GE-Scheine eingeben" <<std::endl;
        return 0;
    }
}

/**
* @brief Behandelt das Rückgeld im Falle eines überbezahlten Betrags.
* 
* Diese Methode berechnet das Rückgeld für einen überbezahlten Betrag und versucht,
* das Rückgeld mit den verfügbaren Geldscheinen auszugeben. Wenn das Rückgeld genau
* passend ausgegeben werden kann, werden die entsprechenden Geldscheine aus der Liste
* der verfügbaren Geldscheine entfernt und das Rückgeld wird dem Benutzer ausgegeben.
* Wenn das Rückgeld nicht genau passend ausgegeben werden kann, wird dem Benutzer die
* Möglichkeit gegeben, anders zu bezahlen oder den Kauf abzubrechen.
* 
* @param preis Der Preis des gekauften Tickets.
* @param bezahlt Der Betrag, der vom Benutzer bezahlt wurde.
* @param geldliste Die Liste der verfügbaren Geldscheine.
* @return Eine Zahl, die den Abschluss des Kaufvorgangs anzeigt: 
*         1, wenn das Rückgeld passend ausgegeben wurde,
*         2, wenn das Rückgeld nicht passend ausgegeben werden konnte und der Benutzer anders bezahlen möchte,
*         0, wenn das Rückgeld nicht passend ausgegeben werden konnte und der Benutzer den Kauf abbrechen möchte.
*/
int Menue::wechselgeldBehandlung(unsigned long int preis, unsigned long int bezahlt, Geldliste& geldliste){
    unsigned long int wechselgeld = bezahlt - preis;
    std::vector<unsigned int> wechselScheine;
    const std::vector<unsigned int> scheinwerte = {17, 11, 7, 5, 3, 2, 1};
    for(const unsigned int& scheinwert : scheinwerte){
        while(wechselgeld >= scheinwert){
            if(geldliste.senkeSorte(scheinwert)){
                wechselScheine.push_back(scheinwert);
                wechselgeld -= scheinwert;
            }
            else{ break; }
        }
    }
    if(wechselgeld == 0){
        Menue::wechselgeldAusgabe(wechselScheine, 1, geldliste);
        return 1;
    }else{
        for(unsigned int schein : wechselScheine){
            geldliste.erhöheSorte(schein);
        }
        int c;
        std::cout   << std::endl << "- Es ist nicht möglich das Rückgeld auszugeben -" <<std::endl
                    << "[1] Anders bezahlen" <<std::endl << "[ ] ansonsten Kauf beenden" <<std::endl <<std::endl << "Eingabe: ";
        std::cin >> c;
        if( c == 1){ return 2; }
        else{
            Menue::clear(); 
            return 0; 
        }
    }    
}

/**
* @brief Gibt das Wechselgeld aus.
* 
* Diese Methode gibt das Wechselgeld auf der Konsole aus. Je nach Wert von `choice` kann das Wechselgeld entweder
* nur ausgegeben oder auch aus der Liste der verfügbaren Geldscheine entfernt werden, der Fall wenn Vorgänge abgebrechen wurden.
* 
* @param ausgabeScheine Ein Vektor, der die Geldscheine für das Wechselgeld enthält.
* @param choice Eine Zahl, die angibt, ob die Geldscheine nur ausgegeben (choice = 1) oder auch aus der Geldliste entfernt werden sollen (choice != 1).
* @param geldliste Die Liste der verfügbaren Geldscheine.
*
* @note die scheine werden ausgegeben wenn das Wechselgeld passend ausgegeben werden kann, 
* weil dort die Anzahl bereits in der `Menue::wechselgeldBehandlung` verringert wurde.
* wurde der Vorgang allerdings abgebrochen wird die Anzahl noch verringert, weil das noch nicht getan wurde 
*/
void Menue::wechselgeldAusgabe(const std::vector<unsigned int>& ausgabeScheine, int choice, Geldliste& geldliste){
    if(choice == 1){
        for(const unsigned int& schein : ausgabeScheine){
            if(schein != 0){
                std::cout  << std::endl <<  "Rückgeld: " << "Schein" + std::to_string(schein) <<std::endl;
            }
        }
    }
    else{
        for(const unsigned int& schein : ausgabeScheine){
            if(schein != 0){
                std::cout  << std::endl <<  "Rückgeld: " << "Schein" + std::to_string(schein) <<std::endl;
                geldliste.senkeSorte(schein);
            }
        }
    }
    std::cout << std::endl;
}

/**
* @brief Generiert, speichert und gibt ein Ticket aus.
* 
* Diese Methode erstellt ein Straßenbahnticket mit den angegebenen Parametern und gibt es auf der Konsole aus.
* Im Falle eines Fehlers beim Erstellen des Tickets wird eine entsprechende Fehlermeldung ausgegeben, und das bezahlte Geld wird ausgegeben.
* 
* @param linie Die Linie der Straßenbahn.
* @param starthaltestelle Die Start-Haltestelle.
* @param endhaltestelle Die End-Haltestelle.
* @param preis Der Preis des Tickets.
* @param gegebeneScheine Ein Vektor, der die eingeworfenen Geldscheine enthält.
* @param geldliste Die Liste der verfügbaren Geldscheine.
* @note Verwendet die Ticket-Klasse. Fängt einen möglichen runtime_error ab, der beim erstellen des Tickets auftreten kann.
*/
void Menue::ticketAusgabe(std::string linie, std::string starthaltestelle, std::string endhaltestelle, unsigned long int preis, std::vector<unsigned int> gegebeneScheine, Geldliste& geldliste){
    try{
        Ticket ticket;      // kann den runtime_error werfen
        ticket.speichernTicket(linie, starthaltestelle, endhaltestelle, preis);
        ticket.ausgabeTicket(linie, starthaltestelle, endhaltestelle, preis);
    } catch(const std::runtime_error& e){
        std::cout << "Fehler beim erstellen des Tickets" << std::endl;
        std::cerr << "Fehler beim Erstellen des Tickets: " << e.what() << std::endl;
        Menue::wechselgeldAusgabe(gegebeneScheine, 2, geldliste);
    }
}
