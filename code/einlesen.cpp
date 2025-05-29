//einlesen.cpp, Funktionen zum Einlesen der Initalisierungsdateien

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Einlesefunktionen für die Initalisierung

std::vector<std::string> read_init_Geldscheine();
std::vector<std::string> read_data_Straßenbahnlinie(std::string);
std::vector<std::string> read_data_Haltestellen(std::string);


/**
* @brief Liest die Initialisierungsdaten für die Geldscheine aus einer Datei.
*
* Die Funktion liest Zeichenketten aus der Datei "Init_Geldscheine.txt",
* die durch Kommas getrennt sind, und gibt sie als Vektor von Zeichenketten zurück.
* Dabei gehören zwei aufeinander folgende Zeichenketten zusammen, 
* die Erste repräsentiert die Sorte,
* die Zweite die Anzahl des Scheins.
*
* @return Ein Vektor von Zeichenketten, wobei zwei aufeiander folgende einen Geldscheine 
* in Sorte und Anzahl repräsentieren.
*
* @details Die Funktion öffnet die Datei, liest Zeichenketten bis zum Ende der Datei
* und fügt jede Zeichenkette, die durch ein Komma getrennt ist, dem Vektor hinzu.
* Dabei ist es wichtig, dass je zwei aufeinanderfolgende Zeichenketten in der Datei 
* einen Geldschein repräsentieren, dafür sollte es im Format "Sorte, Anzahl," geschrieben werden.
* Die Funktion gibt den resultierenden Vektor zurück.
*
* @note Die Funktion geht davon aus, dass die Datei im angegebenen Pfad vorhanden ist.
*       Sie gibt einen leeren Vektor zurück, wenn die Datei nicht geöffnet werden kann.
*       Die Zeichenketten in der Datei sollten durch Kommata getrennt sein.
*/
std::vector<std::string> read_init_Geldscheine(){
    std::vector<std::string> scheine;
    std::string pfad = "Init_Geldscheine.txt";
    std::ifstream file(pfad);
    std::cout << "read_init_Geldscheine" << std::endl;
    if (!file.is_open()) {
        std::cerr << "Fehler (read_init_Geldscheine): Die Datei konnte nicht geöffnet werden." << std::endl;
        return scheine;
    }
    while(file)
    {
        std::string schein;
        std::getline(file, schein, ',');
        if(!schein.empty()){                        //leere Zeilen überspringen
            scheine.push_back(schein);
        }
    }
    std::cout << "read_init_Geldscheine abgeschlossen" << std::endl;
    return scheine;
}

/**
* @brief Liest Daten aus einer Datei für eine Straßenbahnlinie.
* 
* Die Funktion öffnet die Datei "Linie{`filename`}.txt" und liest die ersten zwei Zeilen.
* Die gelesenen Daten werden in einem Vektor von Zeichenketten gespeichert und zurückgegeben.
* 
* @param filename Die Nummer der Straßenbahnlinie, wird in der Funktion zum vollständigen Dateinamen ergänzt.
* 
* @return Ein Vektor von Zeichenketten, der die gelesenen Daten enthält (die ersten beiden Zeilen der Datei).
* 
* @note `filename` ist eine Benutzereingabe, wird in der Funktion `StraßenbahnMenue` eingelesen.
*       Die Funktion geht davon aus, dass die Datei im angegebenen Pfad vorhanden ist.
*       Sie gibt einen leeren Vektor zurück, wenn die Datei nicht geöffnet werden kann.
*/
std::vector<std::string> read_data_Straßenbahnlinie(std::string filename){
    std::vector<std::string> data;
    std::ifstream file("Linien/Linie" + filename +".txt");
    if (!file.is_open()) {
        std::cerr << "Fehler (read_data_Straßenbahnlinie): Die Datei konnte nicht geöffnet werden." << std::endl;
        return data;
    }
    for(unsigned int i = 0; i < 2; i++){        // liest die ersten zwei Zeilen
        std::string zeile;
        std::getline(file, zeile);
        data.push_back(zeile);
    }
    return data;
}

/**
* @brief Liest Daten zu den Haltestellen aus einer Datei für eine Straßenbahnlinie.
* 
* Die Funktion öffnet die Datei "Linie{`filename`}.txt" und überspringt die ersten zwei Zeilen, 
* bevor sie den Rest der Datei liest. Die gelesenen Daten werden in einem Vektor von Zeichenketten gespeichert und zurückgegeben.
* 
* @param filename Die Nummer der Straßenbahnlinie, wird in der Funktion zum vollständigen Dateinamen ergänzt.
* 
* @return Ein Vektor von Zeichenketten, der die gelesenen Daten enthält (ab der dritten Zeile der Datei).
* 
* @note `filename` ist eine Benutzereingabe, wird in der Funktion `StraßenbahnMenue` eingelesen
*       Die Funktion geht davon aus, dass die Datei im angegebenen Pfad vorhanden ist.
*       Sie gibt einen leeren Vektor zurück, wenn die Datei nicht geöffnet werden kann.
*/
std::vector<std::string> read_data_Haltestellen(std::string filename){
    std::vector<std::string> data;
    std::ifstream file("Linien/Linie" + filename +".txt");
    if (!file.is_open()) {
        std::cerr << "Fehler (read_data_Haltestellen): Die Datei konnte nicht geöffnet werden." << std::endl;
        return data;
    }
    for(unsigned int i = 0; i < 2; i++){        //die ersten zwei Zeile werden übersprungen
        std::string dummy;
        std::getline(file, dummy);
    }
    while(file){
        std::string zeile;
        std::getline(file, zeile);
        if(!zeile.empty()){                        //leere Zeilen überspringen
            data.push_back(zeile);
        }
    }
    return data;
}
