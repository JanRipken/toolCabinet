#ifndef CABINET_HPP
#define CABINET_HPP

#include <string>
#include <vector>
#include "./tool.hpp"

class cabinet {
public:
	void searchTool(const std::string& searchTerm); 
	void insertTool(tool _tool);
	void deleteTool(const std::string& werkzeug,const std::string& lagerort);
	void editTool(const std::string& oldtool,const std::string& oldlagerort,
	       const std::string& newtool,const std::string& newlagerort);

	std::vector<tool> getListe();

	void printCabinet();

	std::vector<tool> listeEinlesen();
	void listeSpeichern(std::vector<tool> _cabinet);
	void listeSpeichernJson(std::vector<tool> _cabinet);

private:
	std::vector<tool> _toolcabinet;
	
};

#endif
