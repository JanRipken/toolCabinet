#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include "../header/cabinet.hpp"
#include "../header/tool.hpp"



void hinzufügen(tool &_tool,cabinet &_cabinet,std::string &toolname, std::string &lagerort){

    std::cout <<"------------------------------------------------"<<"\n";
    std::cout <<"Bitte geben sie den Werkzeugnamen ein: ";
    std::cin.ignore();
    std::getline(std::cin, toolname);

    std::cout <<"Bitte geben sie den Lagerort ein: ";
    std::getline(std::cin ,lagerort);
    std::cout <<"------------------------------------------------"<<"\n";


    _tool.setname(toolname);
    _tool.setlagerort(lagerort);

    _cabinet.insertTool(_tool);
}

void bearbeiten(cabinet &_cabinet){
    std::string oldtoolname{};
    std::string oldlagerort{};
    std::string newtoolname{};
    std::string newlagerort{};

    std::cout <<"------------------------------------------------"<<"\n";
    std::cout <<"Bitte geben sie den alten Werkzeugnamen ein: ";
    std::cin.ignore();
    std::getline(std::cin, oldtoolname);

    std::cout <<"Bitte geben sie den alten Lagerort ein: ";
    std::getline(std::cin ,oldlagerort);

    std::cout <<"Bitte geben sie den neuen Werkzeugnamen ein: ";
    std::getline(std::cin ,newtoolname);

    std::cout <<"Bitte geben sie den neuen Lagerort ein: ";
    std::getline(std::cin ,newlagerort);


    std::cout <<"------------------------------------------------"<<"\n";



    _cabinet.editTool(oldtoolname,oldlagerort,newtoolname,newlagerort);
}


void löschen(cabinet &_cabinet){
    std::string toolname{};
    std::string lagerort{};

    std::cout <<"------------------------------------------------"<<"\n";
    std::cout <<"Bitte geben sie den Werkzeugnamen ein: ";
    std::cin.ignore();
    std::getline(std::cin, toolname);

    std::cout <<"Bitte geben sie den Lagerort ein: ";
    std::getline(std::cin ,lagerort);
    std::cout <<"------------------------------------------------"<<"\n";



    _cabinet.deleteTool(toolname,lagerort);
}


void suchen(cabinet &_cabinet){
    std::string searchterm{};

    std::cout <<"------------------------------------------------"<<"\n";
    std::cout <<"Bitte geben sie den Suchbegriff ein: ";
    std::cin.ignore();
    std::getline(std::cin, searchterm);
    std::cout <<"------------------------------------------------"<<"\n";



    _cabinet.searchTool(searchterm);
}


