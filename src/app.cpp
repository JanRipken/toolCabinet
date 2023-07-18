#include "./helper.cpp"

int menu(cabinet &_cabinet){
    tool _tool;
    std::string toolname;
    std::string lagerort;

    int auswahl;
    
    std::cout <<"------------------------------------------------"<<"\n";
    std::cout << "Was wollen sie machen ?" << "\n";
    std::cout << "\n";

    std::cout << "Ein neues Werkzeug hinzufügen: 1" << "\n";
    std::cout << "Ein vorhandene Werkzeug bearbeiten: 2" << "\n";
    std::cout << "Ein vorhandens Werkzeug löschen: 3" << "\n";
    std::cout << "Ein vorhandens Werkzeug suchen: 4" << "\n";
    std::cout << "Alle werkzeuge anzeigen : 5" << "\n";
    std::cout << "Werkzeugliste als CSV Speichern : 6" << "\n";
    std::cout << "Wenn sie das Programm beenden wollen drücken sie: 10"<<"\n"; 
    std::cout <<"------------------------------------------------"<<"\n";


    std::cin >> auswahl;
    switch (auswahl) {
        case 1:
            hinzufügen(_tool,_cabinet,toolname,lagerort);
            break;
        case 2:
            bearbeiten(_cabinet);
            break;
        case 3:
            löschen(_cabinet);
            break;
        case 4:
            suchen(_cabinet);
            break;
        case 5:    
            _cabinet.printCabinet();
            break;
        case 6:
            _cabinet.listeSpeichern(_cabinet.getListe());
            _cabinet.listeSpeichernJson(_cabinet.getListe());
            break;
        case 10:
            return 10;
            break;
    }
    return 0;
}



int main() {
    cabinet _cabinet;
    _cabinet.listeEinlesen();
    int _runner = 0;
    while(_runner!=10){
        _runner = menu(_cabinet);
    }

    return 0;
}
