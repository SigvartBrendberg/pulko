#include "spacecraft.hpp"
#include "state.hpp"
#include "orbit.hpp"

#define ALTITUDE_RADIUS_RATIO 1.05

unsigned long long atmosphericDescent(spacecraft*craft,unsigned int maxFrame){
};

unsigned long long descent(spacecraft*craft,unsigned int maxFrame){
	unsigned long long time = 0;
	if(craft->centralBody->hasAtmosphere){
		/*orbital stuff*/
		while(!craft->dropStage()){};
		time += atmosphericDescent(craft,maxFrame);
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
