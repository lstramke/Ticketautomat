#include <iostream>
#include <fstream>

/**
 * @brief Diese Klasse ermöglicht das Protokollieren von Fehlern in eine Datei.
 * 
 * Die Klasse öffnet beim Erstellen ein Fehlerprotokoll, in das Fehlermeldungen geschrieben werden können.
 * Dabei wird der Ausgabestrom von std::cerr auf diese Datei umgeleitet. Beim Zerstören der Klasse
 * wird die Datei geschlossen und der ursprüngliche Ausgabestrom von std::cerr wiederhergestellt.
 */
class Fehlerlog {
private:
    std::ofstream fehlerLog;
    std::streambuf* alterBuffer;
public:
    /**
    * @brief Konstruktor für die Fehlerlog-Klasse.
    * 
    * Öffnet die angegebene Datei und leitet den Streambuffer von std::cerr auf diese Datei um.
    * 
    * @param filename Der Name der Datei, in die die Fehler umgeleitet werden sollen.
    */
    Fehlerlog(const std::string& filename) : fehlerLog(filename, std::ios::app){
        alterBuffer = std::cerr.rdbuf();
        std::cerr.rdbuf(fehlerLog.rdbuf());
    }

    /**
    * @brief Destruktor für die Fehlerlog-Klasse.
    * 
    * Schließt die Fehlerprotokolldatei und stellt den ursprünglichen Ausgabestrom von std::cerr wieder her.
    */
    ~Fehlerlog(){
        if (fehlerLog.is_open()){
            fehlerLog.close();
        }
        std::cerr.rdbuf(alterBuffer);
    }

};

