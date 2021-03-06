#include <iostream>
#include <string>

#include "propellantLibrary.hpp"
#include "engine.hpp"
#include "stage.hpp"
#include "rocket.hpp"
#include "engines.hpp"
#include "state.hpp"
#include "orbit.hpp"
#include "vehicles.hpp"

int stuff(){
	engine broom(50,1000,10000,&fuel_LH2,&fuel_LOX,2);
	stage proton;
	proton.addEngine(&broom);
	proton.dropEngine(0);
	rocket sojuz;
	sojuz.name = "sojuz";
	return 0;
}
