#include "../header/tool.hpp"
#include <string>

void tool::setlagerort(std::string lagerort){ 
    _lagerort = lagerort;
};

std::string tool::getlagerort(){
    return _lagerort;
};

void tool::setname(std::string name){
    _name = name;
};

std::string tool::getname(){
    return _name;
};

