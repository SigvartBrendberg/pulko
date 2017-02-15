#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "propellantLibrary.hpp"
#include "bodyLibrary.hpp"
#include "parts.hpp"
#include "engines.hpp"
#include "state.hpp"
#include "orbit.hpp"
#include "spacecraft.hpp"

int main(){
	engine broom(50,1000,10000,&fuel_LH2,&fuel_LOX,2);
	stage proton;
	proton.addEngine(&broom);
	proton.dropEngine(0);
	rocket sojuz;
	sojuz.name = "sojuz";
	return 0;
};
