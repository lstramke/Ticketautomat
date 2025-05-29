//main.cpp , Hauptdatei des Projekts

#include "../header/Fehlerlog.hpp"
#include "../header/KLASSE_Menue.hpp"

int main()
{
    //Umleitung der std::cerr-Ausgaben in die fehler_log Datei
    Fehlerlog fehlerlog("Logs/fehler_log.txt");

    //Initalisierung des Geldes

    Geldliste geldliste;
    Menue::initGeld(geldliste);
    
    //Start des Automatenmenüs

    bool automatIstAn = true;
    unsigned int userInteraktion = 0;
    do{
        Straßenbahnliste straßenbahnliste;
        Menue::startMenue();
        userInteraktion = Menue::startAbfrage();
        if(userInteraktion == 1){
            std::string straßenbahnlinie;
            do{
                straßenbahnlinie = Menue::straßenbahnMenue();
            }while(!Menue::straßenbahnAuswahl(straßenbahnlinie, straßenbahnliste));
            Menue::fahrplanAnzeigen(straßenbahnliste);
            std::string starthaltestelle = Menue::starthaltestellenMenue(straßenbahnliste);
            std::string endhaltestelle = Menue::endhaltestellenMenue(straßenbahnliste, starthaltestelle);
            Menue::bezahlMenue(starthaltestelle, endhaltestelle, straßenbahnliste, geldliste);
        }
        else{
            if(Menue::endMenue()){
                break;
            }
        }
    }while(automatIstAn);

    return 0;
}
