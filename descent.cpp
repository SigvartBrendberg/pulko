#include "spacecraft.hpp"
#include "state.hpp"
#include "orbit.hpp"

#define ALTITUDE_RADIUS_RATIO 1.05

unsigned long long atmosphericDescent(spacecraft*craft,unsigned int maxFrame){
	unsigned long long frame = 0;
	craft->spaceMode = false;
	craft->gro = orbitToGround(craft->orb);
	body* centralBody = craft->centralBody;
	double altitude = craft->gro.radius - craft->centralBody->radius;
	double hori = craft->gro.hori;
	double vert = craft->gro.hori;
	while(altitude > 0){
		altitude += vert/maxFrame;
		vert += centralBody->gravity(altitude);
	};
	if(craft->collision(vert)){
		delete craft;
	};
	craft->gro.hori = hori;
	craft->gro.vert = vert;
	return frame;
};

unsigned long long descent(spacecraft*craft,unsigned int maxFrame){
	unsigned long long time = 0;
	if(craft->centralBody->hasAtmosphere){
		/*orbital stuff*/
		while(!craft->dropStage()){};
		time += atmosphericDescent(craft,maxFrame)/maxFrame;
	}
	else{
		orbit lowAltitude(
			craft->orb.gm,
			craft->centralBody->radius * ALTITUDE_RADIUS_RATIO,
			craft->centralBody->radius * ALTITUDE_RADIUS_RATIO,
			craft->orb.inc,
			craft->orb.arg,
			craft->orb.asc
		);
		double cost = transferCost(&craft->orb,&lowAltitude);
	};
	return time;
};
