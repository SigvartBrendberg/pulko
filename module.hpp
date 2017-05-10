#ifndef INC_module_HPP
#define INC_module_HPP

#include <vector>
#include <stack>
#include <iostream>

#include "stage.hpp"

class module{
private:
	std::vector<stage*> boosters;
	std::vector<int> boosterSymetry;
	double mass;
public:
//destructors
	~module(){
		for(unsigned int i = 0; i < boosters.size();i++){
			delete boosters[i];
		};
	};
//info
	double getMass();
	double getThrust();
//actions
	bool dropBooster();
	int produceDeltav(
		double deltav
	);
	double detectDeltav(double pushload){return 0;};//what was the point of this one?
	double produceDeltav(double deltav,double pushLoad){return 0;};//or this one?
};

#endif
