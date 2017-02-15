#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "parts.h"
#include "propellants.h"
#include "engines.h"
#include "state.h"
#include "orbit.h"
#include "body.h"
#include "spacecraft.h"

int main(){
	body sun(1.32712440018e20,695700000);//sun
	sun.addChild(3.986004418e14,6371000);//earth
	sun.latestChild() -> addChild(4.9048695e12,1737100);//moon

	engine broom(50,1000,10000,&fuel_LH2,&fuel_LOX,2);
	stage proton;
	proton.addEngine(&broom);
	proton.dropEngine(0);
	rocket sojuz;
	sojuz.name = "sojuz";
	return 0;
};
