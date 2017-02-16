#ifndef INC_capsule_HPP
#define INC_capsule_HPP

#include <vector>

#include "cosmonaut.hpp"

class capsule{
private:
	double ablator;
	double temperature;
	std::vector<cosmonaut*> crew;
public:
	double friction;
	double mass;
	unsigned int crewCapacity;
};

#endif
