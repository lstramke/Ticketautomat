/* tests.cpp , enthält Tests zu den Funktionen des Hauptprogramms und kann zur 
Durchführung alterntaiv zur main.cpp mit kompiliert werden

Kompilierbefehl:

clang++ -Weverything -std=c++17 -Wno-c++98-compat tests.cpp menue.cpp straßenbahn.cpp einlesen.cpp geld.cpp geldliste.cpp straßenbahnliste.cpp ticket.cpp -o Tests

Die Datei ruft die unterschiedlichen Funktionen mit unterschiedlichen Werten auf um die Funktionsweise 
gekapselt testen zu können, dabei sind bei einigen Funktionen auch freie Eingaben möglich.
*/

#include "../header/KLASSE_Menue.hpp"
#include <iostream>

void test_GeldInitalisierung();
void test_StartEingabe();
void test_StraßenbhanAuswahl(std::string, Straßenbahnliste&);
void test_FahrplanAusgabe();
void test_StarthaltestellenEingabe();
void test_Bezahlvorgang();
void test_Endmenue();

int main(){

    std::cout << "_______ Tests _______" << std::endl;

    //1. Test: Einlesen der Initalisierungswerte des Geldes
    test_GeldInitalisierung();

    //2. Test: Starteingabe
    test_StartEingabe();

    //3. Test: Straßenbahnauswahl
    std::vector<std::string> testcases = {"11", "4", "15", "0", "Abcdef", "4abce", "abdg4"};
    std::cout   << std::endl << "---- Test des Straßenbahnauswahl ----" << std::endl
                << "Erwartung: Einlesen der gesuchten Linie, wenn diese existiert und die Ausgabe true bzw. 1," << std::endl
                << "ansonsten eine Fehlermeldung und die Ausgabe false bzw. 0." << std::endl
                << std::endl << "Testcases: 11, 4, 15, 0, Abcdef, 4abce, abdg4" << std::endl
                << "Die ersten drei Testcases existieren, die Ausgabe sollte 1 sein, bei den Restlichen Fehlermeldung und 0" << std::endl;
    for( std::string testcase : testcases){
        Straßenbahnliste straßenbahnliste;
        test_StraßenbhanAuswahl(testcase, straßenbahnliste);
    }

    //4. Test: Fahrplanausgabe

    std::cout   << std::endl << "---- Test der Fahrplanausgabe ----" << std::endl
                << "Überprüfung per Vergleich der Datei die eingelesen wurde un der Ausgabe auf der Konsole." << std::endl
                << "Erwartung: Linienname und Auflistung aller Haltestellen der Linie und die neue Überschrift Haltestellenauswahl" << std::endl
                << "bei Übergabe einer Leerenstraßenbahnliste, wird eine Fehlermeldung ausgegeben" << std::endl
                << std::endl;
    test_FahrplanAusgabe();

    //5. Test: Test der Halestellenüberprüfung bei der Auswahl

    test_StarthaltestellenEingabe();

    //6. Test: Test des Bezahlvorgangs
    while(true){
        test_Bezahlvorgang();
        int choice;
        std::cout << std::endl << "nächstes Szenario testen 1 eingeben ansonsten was anderes: ";
        std::cin >> choice;
        if(choice != 1){break;}
    }

    //7. Test: Test des Endmenüs
    while(true){
        test_Endmenue();
        int choice;
        std::cout << std::endl << "nächstes Szenario testen 1 eingeben ansonsten was anderes: ";
        std::cin >> choice;
        if(choice != 1){break;}
    }
    std::cout << std::endl << "---- Alle Tests durchgeführt ----" << std::endl;
}

//Implementierungen

/**
* @brief Testet die Initialisierung der Geldliste.
* 
* Diese Funktion erstellt eine Geldliste und initialisiert sie gemäß den Werten in der Datei Init_Geldscheine.
* Anschließend wird die erstellte Geldliste ausgegeben, um sicherzustellen, 
* dass die Initialisierung korrekt erfolgt ist, mit den Werten in der Datei vergleichen.
* 
* @test Die Funktion soll sicherstellen, dass die Geldliste mit den erwarteten Geldscheinen und Mengen initialisiert wird.
*       Die erwarteten Geldscheine und Mengen sind 17er, 11er, 7er, 5er, 3er, 2er und 1er, jeweils mit der Anzahl von 2.
*       Die Ausgabe sollte die initialisierte Geldliste entsprechend den erwarteten Werten enthalten.
*/
void test_GeldInitalisierung(){
    Geldliste geldliste;
    std::cout   << std::endl << "---- Test des Geldinitalisierung ----" << std::endl
                << "Erwartung: Ausgabe einer Geldliste, bei der die Sorten 17,11,7,5,3,2,1 mit jeweils der Anzahl von 2 initalisiert wurden" << std::endl
                << "bzw. so wie es in der Datei Init_Geldscheine steht" << std::endl
                << "Ausgabe: " << std::endl;
    Menue::initGeld(geldliste);
    geldliste.ausgabeListe();
}

/**
* @brief Testet die Funktion startAbfrage.
* 
* Diese Funktion ermöglicht es, beliebige Eingaben an die Funktion startAbfrage zu senden und das Verhalten zu überprüfen.
* 
* @test Es werden verschiedene Szenarien getestet, um sicherzustellen, dass die Funktion korrekt auf verschiedene Arten von Eingaben reagiert.
*       - Bei Eingabe der Zahlen 1 oder 2 soll die entsprechende Zahl zurückgegeben werden.
*       - Bei Eingabe von anderen Zahlen soll eine Fehlermeldung ausgegeben und eine erneute Eingabeaufforderung erfolgen.
*       - Bei Eingabe von Buchstaben soll ebenfalls eine Fehlermeldung ausgegeben und eine erneute Eingabeaufforderung erfolgen.
*       - Wenn zuerst eine Zahl und dann Buchstaben eingegeben werden, werden die Buchstaben ignoriert und nur die Zahl berücksichtigt.
*       - Wenn die eingegebene Zahl 1 oder 2 ist, wird sie zurückgegeben. Ansonsten wird eine Fehlermeldung ausgegeben und eine erneute Eingabeaufforderung erfolgt.
*       - Zu testende Eingaben: 1, 2, 3, 0, a, A, abcsdQ, 1bajaf, 2njda, 3vsah, cavh1
* @note Die Ausgabe des Tests erfolgt in Form von Zahlen, die von der Funktion startAbfrage zurückgegeben werden, sowie von Fehlermeldungen, die bei ungültigen Eingaben ausgegeben werden.
*/
void test_StartEingabe(){
    std::cout   << std::endl << "---- Test der startAbfrage ----" << std::endl
                << "Beliebige Eingaben auf die Funktion möglich." << std::endl
                << "Erwartung: " <<std::endl
                << "bei Eingabe der Zahlen 1 oder 2 ---> Ausgabe der ensprechenden Zahl" << std::endl
                << "bei Eingabe von anderen Zahlen ---> Ausgabe einer Fehlermeldung und erneute Eingabeaufforderung" << std::endl
                << "bei Eingabe von Buchstaben ---> Ausgabe einer Fehlermeldung und erneute Eingabeaufforderung" << std::endl
                << "bei Eingabe von Zahlen und Buchstaben ---> Wenn zuerst eine Zahl und danach Buchstaben, wird alles nach der ersten Zahl ignoriert. " << std::endl
                << "Wenn die zahl 1 oder 2 ist wird sie zurückgegeben ansonsten Fehlermeldung und erneute Eingabe." << std::endl
                << "-- zu testende Eingaben: 1, 2, 3, 0, a, A , abcsdQ, 1bajaf, 2njda, 3vsah, cavh1 --" << std::endl
                << "Ausgaben:" <<std::endl;
    bool weiterEingabeTesten = true;
    while(weiterEingabeTesten){
        std::cout << Menue::startAbfrage() << std::endl;
        std::cout << std::endl << "Für weitern Test 1 tippen: ";
        int eingabe;
        std::cin >> eingabe;
        if(eingabe != 1){
            weiterEingabeTesten = false;
        }
    }          
    Menue::clear();
}

/**
* @brief Testet die Funktion zur Auswahl einer Straßenbahnlinie.
* 
* Diese Funktion führt eine Reihe von Tests für die Funktion `Menue::straßenbahnAuswahl()` durch, indem sie verschiedene Liniennummern überprüft.
* 
* @param liniennummer Die zu testende Liniennummer als Zeichenkette.
* @param straßenbahnliste Die Liste der verfügbaren Straßenbahnen, in der die Auswahl erfolgen soll.
* 
* @test Es werden verschiedene Testfälle durchgeführt, um die Funktionalität der Straßenbahnauswahl zu überprüfen:
*       - Für gültige Liniennummern wird erwartet, dass die Funktion `straßenbahnAuswahl` true zurückgibt.
*       - Für ungültige Liniennummern wird erwartet, dass die Funktion `straßenbahnAuswahl` false zurückgibt.
* 
* @note Die Ausgabe jedes Tests wird auf der Konsole angezeigt, wobei 1 für gültige Liniennummern und 0 für ungültige Liniennummern erwartet wird.
*/
void test_StraßenbhanAuswahl(std::string liniennummer, Straßenbahnliste& straßenbahnliste){
    std::cout   << "Ausgabe: " << std::endl
                << Menue::straßenbahnAuswahl(liniennummer, straßenbahnliste) << std::endl;
}

/**
* @brief Testet die Funktion zur Ausgabe des Fahrplans.
* 
* Diese Funktion überprüft die Funktionalität der Funktion `fahrplanAnzeigen`, indem sie den Fahrplan einer bestimmten Straßenbahnlinie
* auf der Konsole ausgibt und ihn mit der erwarteten Ausgabe vergleicht, die aus einer externen Datei eingelesen wurde.
* 
* @test
*   Es werden verschiedene Aspekte der Fahrplanausgabe getestet:
*   - Die korrekte Darstellung des Liniennamens und der Auflistung aller Haltestellen der Linie.
*   - Die neue Überschrift "Haltestellenauswahl" nach der Ausgabe des Fahrplans.
*   - Die korrekte Reaktion auf die Übergabe einer leeren Straßenbahnliste, was zu einer Fehlermeldung führen sollte.
* @note Die Ausgabe des Tests erfolgt durch Vergleich der auf der Konsole ausgegebenen Fahrplaninformationen mit den erwarteten Informationen,
*       die aus einer externen Datei eingelesen wurden.
*/
void test_FahrplanAusgabe(){
    std::vector<std::string> testcases2 = {"11", "4"};
    std::cout   << "Ausgabe für leere Straßenbahnliste:" << std::endl;
    Straßenbahnliste straßenbahnliste;
    Menue::fahrplanAnzeigen(straßenbahnliste);
    std::cout   << std::endl << "Ausgabe für gültige Straßenbahnliste in zwei Fällen:" << std::endl;
    for(std::string testcase : testcases2){
        Straßenbahnliste straßenbahnliste1;
        Menue::straßenbahnAuswahl(testcase, straßenbahnliste1);
        Menue::fahrplanAnzeigen(straßenbahnliste1);
    }
}

/**
* @brief Testet die Funktion zur Auswahl einer Starthaltestelle.
* 
* Diese Funktion testet die Funktionalität der Funktion `Menue::starthaltestellenMenue()`, indem sie die Auswahl einer Start-Haltestelle für eine bestimmte Straßenbahnlinie überprüft.
* 
* @test Es wird exemplarisch für die Linie 11 getestet, ob die Funktion korrekt auf die Eingabe einer existierenden oder nicht existierenden Haltestelle reagiert.
*       - Wenn die eingegebene Haltestelle existiert, wird ihr Name erwartungsgemäß zurückgegeben.
*       - Wenn die eingegebene Haltestelle nicht existiert, wird eine Fehlermeldung erwartet und eine erneute Eingabeaufforderung durchgeführt.
* 
* @note Die Ausgabe des Tests erfolgt auf der Konsole, wobei erwartet wird, dass der Name der ausgewählten Haltestelle zurückgegeben wird,
*       wenn sie existiert, und dass eine Fehlermeldung ausgegeben wird, wenn die Haltestelle nicht existiert.
*/
void test_StarthaltestellenEingabe(){
    Straßenbahnliste straßenbahnliste;
    Menue::straßenbahnAuswahl("11", straßenbahnliste);
    std::cout   << std::endl << "---- Test der Haltestellenauswahl ----" << std::endl
                << "Es wird für die Linie 11 exemplarisch getestet." << std::endl
                << "Erwartung: Wenn die Haltestelle existiert wird ihr Name zurückgegeben" << std::endl
                << "ansonsten gibt es eine Fehlermeldung und eine erneute Eingabe wird abgefragt." << std::endl
                << "nicht existierende Haltestelle: Ostplatz | Existierende Haltestelle: HTWK " << std::endl
     << Menue::starthaltestellenMenue(straßenbahnliste) << std::endl;

}

/**
* @brief Testet den Bezahlvorgang exemplarisch für die Fahrt von der Leinestraße bis zur HTWK.
* 
* Diese Funktion überprüft die Funktionalität des Bezahlvorgangs für die Fahrt von der Leinestraße bis zur HTWK.
* Dabei werden verschiedene Eingabeszenarien für die Bezahlung getestet und die Ausgabe der Geldliste vor und nach dem Bezahlvorgang kontrolliert.
* 
* @test Es werden folgende Eingabeszenarien getestet:
*   - Passende Bezahlung mit verschiedenen Scheinen.
*   - Bezahlung mit Scheinen, bei denen Rückgeld gegeben werden kann.
*   - Bezahlung mit Scheinen, bei denen kein Rückgeld gegeben werden kann.
*   - Abbruch des Bezahlvorgangs durch Eingabe von 0.
*   - Eingabe von Buchstaben oder ungültigen Scheinzahlen, die eine Fehlermeldung auslösen.
*   - Eingabe einer gültigen Scheinzahl gefolgt von Buchstaben, wobei die Buchstaben ignoriert und die Zahl gewertet wird.
* 
* @note Die Ausgabe des Tests erfolgt auf der Konsole, wobei die Geldliste vor und nach dem Bezahlvorgang ausgegeben wird,
*       um sicherzustellen, dass die Bezahlung korrekt verarbeitet wurde.
*/
void test_Bezahlvorgang(){
    std::cout   << std::endl << "---- Test des Bezahlvorgangs ----" << std::endl
                << "Es wird von der Leinestraße bis zur HTWK gefahren, Ausgabe der Geldliste davor und danach als Kontrolle" << std::endl
                << "Erwartung: Preis für 7 Haltestellen = 21, verschieden Eingabeszenarien:" << std::endl
                << "1. passend bezahlt, dafür 11, 5, 5 eingeben --> Ticket wird ausgegeben" << std::endl
                << "2. bezahlt Rückgeld kann gegeben werden, dafür 17, 5 eingeben --> 1Schein zurück + Ticket wird ausgegeben" << std::endl
                << "3. bezahlt Rückgeld kann nicht gegeben werden dafür 17, 7 eingeben --> Meldung und Auswahl ob anders bezahlen oder abbrechen " << std::endl
                << "4. 0 eingegeben --> Vorgang wird abgebrochen" << std::endl
                << "5. Buchstaben oder ungültige 'Schein'zahlen werden eingegeben --> Fehlermeldung, erneute Aufforderung" << std::endl
                << "Wird eine gültige Scheizahl gefolgt von Buchstaben eingegeben werden die Buchstaben ignoriert und die Zahl gewertet." <<std::endl;
    Straßenbahnliste straßenbahnliste;
    Menue::straßenbahnAuswahl("11", straßenbahnliste);
    std::string start = "Leinestraße";
    std::string end = "HTWK";
    Geldliste geldliste;
    std::vector<std::string> initGeld = {"schein17", "0", "schein11", "0", "schein7", "0", "schein5", "0",
                                         "schein3", "0", "schein2", "0", "schein1", "1"};
    for(unsigned int k=0; k < initGeld.size()-1; k+=2){
        geldliste.addGeld(Geld(initGeld.at(k), std::stoul(initGeld.at(k+1))));   
    }
    geldliste.ausgabeListe();
    Menue::bezahlMenue(start, end, straßenbahnliste, geldliste);
    geldliste.ausgabeListe();
}

/**
* @brief Testet das Endmenü.
* 
* Diese Funktion überprüft die Funktionalität des Endmenüs.
* Dabei wird erwartet, dass bei der Eingabe von 1 das Programm beendet wird und true bzw. 1 zurückgegeben wird,
* während bei jeder anderen Eingabe false bzw. 0 zurückgegeben wird.
* 
* @note Die Ausgabe des Tests erfolgt auf der Konsole, wobei das Ergebnis des Endmenüs angezeigt wird.
*/
void test_Endmenue(){
    std::cout   << std::endl << "---- Testen des Endmenüs ----" << std::endl
                << "Erwartung: bei der Eingabe von 1 wird beendet und true bzw. 1 ausgegeben" << std::endl
                << "bei jeder andern Eingabe wird false bzw. 0 zurückgegeben" << std::endl
                << Menue::endMenue() << std::endl; 
}
