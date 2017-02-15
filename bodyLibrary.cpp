#include "body.hpp"

body* init_solarSystem(){
body* MOUNT = new body(); //no parent value
body*sun = new body(1.32712440018e20,695700000,MOUNT,"sun");
	body*mercury = new body(sun,"mercury");
	body*venus = new body(sun);
	body*earth = new body(3.986004418e14,6371000,sun,"earth");
		body*moon = new body(4.9048695e12,1737100,earth,"moon");
	body*mars = new body(sun,"mars");
		body*phobos = new body(mars,"phobos");
		body*deimos = new body(mars,"deimos");
	body*ceres = new body(sun,"ceres");
	body*pallas = new body(sun);
	body*vesta = new body(sun);
	body*jupiter = new body(sun);
	body*saturn = new body(sun);
	body*uranus = new body(sun);
	body*neptune = new body(sun);
	body*pluto = new body(sun);
	body*eris = new body(sun);
	return MOUNT;
};
