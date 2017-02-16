#ifndef INC_atmosphere_HPP
#define INC_atmosphere_HPP

#include <vector>

#include "propellants.hpp"

struct atmosphereLayer{
	double ceiling;
	double basePressure;
	double baseTemperature;
	double temperatureGradient;

	double density(double altitude){
		return 666;//place holder
	};
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

	double density(double altitude){
		if(altitude > ceiling){
			return 0;//vacuum
		};
		for(unsigned int i=layers.size()-1;altitude > layers[i].ceiling;i--){
			return layers[i].density(altitude);
		};
	};
};

#endif
