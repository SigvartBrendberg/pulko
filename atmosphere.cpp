#include <vector>
#include <cmath>

#include "physicsConstants.hpp"
#include "atmosphere.hpp"

double atmosphereLayer::density(double altitude,double gravity,double molarMass){
	return basePressure * std::pow(
		1 - temperatureGradient * altitude/(
			baseTemperature + KELVIN_TO_CELSIUS
		),
		gravity * molarMass/(IDEAL_GAS_CONSTANT * temperatureGradient)
	);//https://en.wikipedia.org/wiki/Density_of_air
};
	
double atmosphere::molarMass(){
};

double atmosphere::density(double altitude,double gravity){
	if(altitude > ceiling){
		return 0;//vacuum
	};
	for(unsigned int i=layers.size()-1;altitude > layers[i].ceiling;i--){
		return layers[i].density(altitude,gravity,molarMass());
	};
};
