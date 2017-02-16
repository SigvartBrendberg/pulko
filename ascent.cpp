#include <iostream>

#include "spacecraft.hpp"
#include "state.hpp"

int launchCheck(spacecraft*craft,double altitude){
	double acceleration = craft->gravAcceleration();
	double thrust = craft->getThrust();
	if(thrust < acceleration){
		return 1;
	};
};

unsigned long long ascent(spacecraft*craft,double altitude,unsigned int maxFrame){
	if(launchCheck(craft,altitude)){
		std::cout << "launch failed" << std::endl;
		return 1;
	};
};
