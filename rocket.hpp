#ifndef INC_rocket_HPP
#define INC_rocket_HPP

#include <vector>
#include <stack>
#include <iostream>

#include "module.hpp"

struct payload{
	double mass;
	payload():mass(0){};
	payload(
		double i_mass
	):
		mass(i_mass)
	{};
};

class rocket{
private:
	std::stack<module*,std::deque<module*> > modules;
	std::vector<payload*> payloads;
	double mass;
public:
//variables
	std::string name;
//constructors
	rocket():
		mass(0),
		name("unnamed")
	{};
//destructors
	~rocket(){
		std::cout << name << " has been destroyed" << std::endl;
		while(!modules.empty()){
			delete modules.top();
			modules.pop();
		};
		for(unsigned int i = 0; i < payloads.size();i++){
			delete payloads[i];
		};
	};
//info
	double getMass();
	double getThrust();
//actions
	int addPayload(
		payload* newPayload
	);
	int dropPayload(
		unsigned int payloadIndex
	);
	bool dropModule();
	int produceDeltav(
		double deltav
	);
};

#endif
