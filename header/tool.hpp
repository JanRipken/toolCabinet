#ifndef TOOL_HPP
#define TOOL_HPP

#include <string>

class tool {
public:
    std::string getname();
    void setname(std::string name);

    std::string getlagerort();
    void setlagerort(std::string lagerort);

private:
    std::string _name;
    std::string _lagerort;
};

#endif // TOOL_HPP

