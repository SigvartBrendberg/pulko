#include <cmath>

#include "state.h"

orbit groundToOrbit(ground* initial){
	orbit target;
	target.gm = initial->gm;
	/*
	*/
	return target;
}

ground orbitToGround(orbit* initial){
	ground target;
	target.gm = initial->gm;
	target.radius = initial->radius();
	target.hori = initial->horisontalSpeed();
	double speed = initial->speed();
	target.vert = std::sqrt(speed*speed - target.hori*target.hori);
	/*
	*/
	return target;
}
