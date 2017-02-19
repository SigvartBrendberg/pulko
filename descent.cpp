#include "spacecraft.hpp"
#include "state.hpp"
#include "orbit.hpp"

#define ALTITUDE_RADIUS_RATIO 1.05

unsigned long long spacecraft::atmosphericDescent(unsigned int maxFrame){
	unsigned long long frame = 0;
	spaceMode = false;
	gro = orbitToGround(orb);
	double altitude = gro.radius - centralBody->radius;
	double hori = gro.hori;
	double vert = gro.hori;
	while(altitude > 0){
		altitude += vert/maxFrame;
		vert += centralBody->gravity(altitude);
	};
	if(collision(vert)){
		delete this;
	};
	gro.hori = hori;
	gro.vert = vert;
	return frame;
};

unsigned long long spacecraft::descent(unsigned int maxFrame){
	unsigned long long time = 0;
	if(centralBody->hasAtmosphere){
		/*orbital stuff*/
		while(!dropStage()){};
		time += atmosphericDescent(maxFrame)/maxFrame;
	}
	else{
		orbit lowAltitude(
			orb.gm,
			centralBody->radius * ALTITUDE_RADIUS_RATIO,
			centralBody->radius * ALTITUDE_RADIUS_RATIO,
			orb.inc,
			orb.arg,
			orb.asc
		);
		double cost = transferCost(&orb,&lowAltitude);
	};
	return time;
};
