#ifndef INC_spacecraft_HPP
#define INC_spacecraft_HPP

#include "body.hpp"
#include "state.hpp"
#include "parts.hpp"

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
	bool dropStage(){
		hardware->dropStage();
	};
};

#endif
