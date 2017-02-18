#ifndef INC_parts_HPP
#define INC_parts_HPP

#include <cmath>
#include <vector>
#include <stack>
#include <iostream>

#include "propellant.hpp"
#include "basic_part.hpp"
#include "engine.hpp"
#include "stage.hpp"

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
	std::stack<stage*,std::deque<stage*> > stages;
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
		while(!stages.empty()){
			delete stages.top();
			stages.pop();
		};
		for(unsigned int i = 0; i < payloads.size();i++){
			delete payloads[i];
		};
	};
//info
	double getMass(){
		return mass;
	};
	double getThrust(){
		return stages.top()->getThrust();
	};
//actions
	int addPayload(payload* newPayload){
		payloads.push_back(newPayload);
		mass += newPayload->mass;
		return 0;
	};
	int dropPayload(unsigned int payloadIndex){
		if(payloads.size() <= payloadIndex){
			return 1;//no such payload
		};
		mass -= payloads[payloadIndex]->mass;
		delete payloads[payloadIndex];
		payloads.erase(payloads.begin()+payloadIndex);
		return 0;
	};
	bool dropStage(){
		if(!stages.empty()){
			stage* topp = stages.top();
			stages.pop();
			mass -= topp->getMass();
			delete topp;
			return false;
		};
		return true;
	};
	int produceDeltav(double deltav){
		while(deltav > 0){
			if(stages.empty()){
				return 1;//not enough deltav in stages to reach target value
			};
			double pushLoad = mass - stages.top()->getMass();
			double nextStep = stages.top()->detectDeltav(pushLoad);
			if(deltav > nextStep){
				deltav -= nextStep;
				dropStage();
			}
			else{
				stages.top()->produceDeltav(deltav,pushLoad);
				break;
			};
		};
		return 0;
	};
};

#endif
