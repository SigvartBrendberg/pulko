#ifndef INC_spacecraft_HPP
#define INC_spacecraft_HPP

#include "body.hpp"
#include "state.hpp"
#include "parts.hpp"

class spacecraft{
private:
	unsigned long long timeStamp;
	ground gro;
	rocket* hardware;
public:
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
	double getThrust(){
		return hardware->getThrust();
	};
	int dropStage(){
		if(hardware->dropStage()){
			return 1;
		};
		return 0;
	};
};

#endif
