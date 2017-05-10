#ifndef INC_spacecraft_HPP
#define INC_spacecraft_HPP

#include "body.hpp"
#include "state.hpp"
#include "rocket.hpp"

class spacecraft{
private:
	double collisionRestistance;
	unsigned long long timeStamp;
	rocket* hardware;
public:
	ground gro;
	orbit orb;
	body* centralBody;
	bool spaceMode;
	spacecraft():
		spaceMode(false)
	{};
	double gravAcceleration(){
		if(spaceMode){
			return orb.gm/(orb.radius()*orb.radius());
		}
		else{
			return gro.gm/(gro.radius*gro.radius);
		};
	};
	bool collision(double speed){
		if(speed > collisionRestistance){
			return true;
		};
		return false;
	};
	double getThrust(){
		return hardware->getThrust();
	};
//actions
	bool dropStage(){
		hardware->dropModule();
	};
	unsigned long long escape();
	unsigned long long ascent(double altitude,unsigned int maxFrame);
	int launchCheck(double altitude);
	unsigned long long atmosphericDescent(unsigned int maxFrame);
	unsigned long long descent(unsigned int maxFrame);
};

#endif
