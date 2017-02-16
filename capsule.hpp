#ifndef INC_capsule_HPP
#define INC_capsule_HPP

#include <vector>

#include "cosmonaut.hpp"

class capsule{
private:
	std::vector<cosmonaut*> crew;
public:
	unsigned int crewCapacity;
};

#endif
