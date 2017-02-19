#include <iostream>

#include "spacecraft.hpp"
#include "state.hpp"

int spacecraft::launchCheck(double altitude){
	double acceleration = gravAcceleration();
	double thrust = getThrust();
	if(thrust < acceleration){
		return 1;
	};
};

unsigned long long spacecraft::ascent(double altitude,unsigned int maxFrame){
	if(launchCheck(altitude)){
		std::cout << "launch failed" << std::endl;
		return 1;
	};
};
