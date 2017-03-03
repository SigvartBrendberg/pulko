#ifndef INC_atmosphere_HPP
#define INC_atmosphere_HPP

#include <vector>

#include "compounds.hpp"

struct atmosphereLayer{
	double ceiling;
	double basePressure;
	double baseTemperature;
	double temperatureGradient;

	double density(double altitude,double gravity,double molarMass);
};

struct gasPart{
	compound* stuff;
	double share;
};

class atmosphere{
private:
	std::vector<atmosphereLayer> layers;
public:
	double ceiling;
	std::vector<gasPart> compositon;
	
	double molarMass();

	double density(double altitude,double gravity);
};

#endif
