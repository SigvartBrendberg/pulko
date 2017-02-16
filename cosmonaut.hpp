#ifndef INC_cosmonaut_HPP
#define INC_cosmonaut_HPP

#include <string>
#include <vector>

#include "skill.hpp"

class cosmonaut{
private:
	std::vector<skill*> skills;
public:
	std::string name;
	bool gender;
	unsigned short age;
	cosmonaut():
		/*something random*/
	{};
};

#endif
