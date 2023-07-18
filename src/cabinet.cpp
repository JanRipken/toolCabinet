#include "../header/cabinet.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <jsoncpp/json/json.h>


std::vector<tool>& cabinet::getListe(){
    return _toolcabinet;
};


void cabinet::insertTool(tool& tool){
    _toolcabinet.push_back(tool);    
};


void cabinet::printCabinet(){
    std::cout <<"------------------------------------------------"<<"\n";
    for(std::vector<tool>::size_type i = 0;i<_toolcabinet.size();i++){
        std::cout << "Werkzeug: " << _toolcabinet[i].getname()<<"\n";
        std::cout << "Lagerort: " << _toolcabinet[i].getlagerort()<<"\n";
        std::cout << " " << std::endl;
    };
    std::cout <<"------------------------------------------------"<<"\n";
};
;

std::vector<tool> cabinet::listeEinlesenJson() {
    const std::string filename = "data/data.json";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der JSON-Datei zum Lesen.\n";
        return _toolcabinet;
    }

    Json::Value cabinetJson;
    file >> cabinetJson;

    for (const Json::Value& toolJson : cabinetJson) {
        std::string name = toolJson["name"].asString();
        std::string lagerort = toolJson["lagerort"].asString();
        tool _tool;
        _tool.setname(name);
        _tool.setlagerort(lagerort);
        _toolcabinet.push_back(_tool);
    }

    file.close();
    return _toolcabinet;
}



void cabinet::listeSpeichernJson(std::vector<tool>& toolcabinet) {
    const std::string filename = "data/data.json";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der JSON-Datei zum Speichern.\n";
        return;
    }

    Json::Value cabinetJson(Json::arrayValue);
    for (tool& tool : toolcabinet) {
        Json::Value toolJson;
        toolJson["name"] = tool.getname();
        toolJson["lagerort"] = tool.getlagerort();
        cabinetJson.append(toolJson);
    }

    Json::StyledStreamWriter writer;
    writer.write(file, cabinetJson);

    file.close();
};


void cabinet::deleteTool(const std::string& name, const std::string& lagerort) {
    auto it = std::remove_if(_toolcabinet.begin(), _toolcabinet.end(), [&](tool& t) { 
        return t.getname() == name && t.getlagerort() == lagerort;
    });
    
    if (it != _toolcabinet.end()) {
        _toolcabinet.erase(it, _toolcabinet.end());
        std::cout << "Werkzeug '" << name << "' am Lagerort '" << lagerort << "' wurde gelöscht.\n";
    } else {
        std::cout << "Werkzeug '" << name << "' am Lagerort '" << lagerort << "' existiert nicht im Schrank.\n";
    }
}


void cabinet::editTool(const std::string& oldName, const std::string& oldLagerort, const std::string& newName, const std::string& newLagerort) {
    auto it = std::find_if(_toolcabinet.begin(), _toolcabinet.end(), [&](tool& t) { 
        return t.getname() == oldName && t.getlagerort() == oldLagerort;
    });
    
    if (it != _toolcabinet.end()) {
        it->setname(newName);
        it->setlagerort(newLagerort);
        std::cout << "Werkzeug '" << oldName << "' am Lagerort '" << oldLagerort << "' wurde bearbeitet.\n";
        std::cout << "Neuer Name: " << newName << ", Neuer Lagerort: " << newLagerort << "\n";
    } else {
        std::cout << "Werkzeug '" << oldName << "' am Lagerort '" << oldLagerort << "' existiert nicht im Schrank.\n";
    }
}

void cabinet::searchTool(const std::string& searchTerm) {
    std::vector<tool> foundTools;

    for (tool& t : _toolcabinet) {
        if (t.getname().find(searchTerm) != std::string::npos || t.getlagerort().find(searchTerm) != std::string::npos) {
            foundTools.push_back(t);
        }
    }

    if (foundTools.empty()) {
        std::cout << "Kein Werkzeug mit dem Suchbegriff '" << searchTerm << "' gefunden.\n";
    } else {
        std::cout << "Folgende Werkzeuge enthalten den Suchbegriff '" << searchTerm << "':\n";
        for ( tool& t : foundTools) {
            std::cout << "Werkzeug: " << t.getname() << ", Lagerort: " << t.getlagerort() << "\n";
        }
    }
}


