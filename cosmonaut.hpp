#ifndef INC_cosmonaut_HPP
#define INC_cosmonaut_HPP

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "skill.hpp"

class cosmonaut{
private:
	std::vector<skill*> skills;
public:
	std::string name;
	bool gender;
	unsigned short age;
	cosmonaut():
		gender((bool)std::rand()%2)
	{};
	~cosmonaut(){
		std::cout << "the cosmonaut object " << name << " has been deleted. It may be in a log file" << std::endl;
		for(unsigned int i=skills.size();i--;){
				delete skills[i];
		};
	};
};

#endif
