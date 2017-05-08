#ifndef INC_module_HPP
#define INC_module_HPP

#include <vector>
#include <stack>
#include <iostream>

#include "stage.hpp"

class module{
private:
	std::stack<stage*,std::deque<stage*> > boosters;
	std::vector<int> boosterSymetry;
	double mass;
public:
//destructors
	~module(){
		while(!boosters.empty()){
			delete boosters.top();
			boosters.pop();
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
};

#endif
