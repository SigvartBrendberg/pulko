#include "rocket.hpp"

double rocket::getMass(){
		return mass;
};
double rocket::getThrust(){
	return modules.top()->getThrust();
};
//actions
int rocket::addPayload(payload* newPayload){
	payloads.push_back(newPayload);
	mass += newPayload->mass;
	return 0;
};
int rocket::dropPayload(unsigned int payloadIndex){
	if(payloads.size() <= payloadIndex){
		return 1;//no such payload
	};
	mass -= payloads[payloadIndex]->mass;
	delete payloads[payloadIndex];
	payloads.erase(payloads.begin()+payloadIndex);
	return 0;
};
bool rocket::dropModule(){
	if(!modules.empty()){
		module* topp = modules.top();
		modules.pop();
		mass -= topp->getMass();
		delete topp;
		return false;
	};
	return true;
};
int rocket::produceDeltav(double deltav){
	while(deltav > 0){
		if(modules.empty()){
			return 1;//not enough deltav in stages to reach target value
		};
		double pushLoad = mass - modules.top()->getMass();
		double nextStep = modules.top()->detectDeltav(pushLoad);
		if(deltav > nextStep){
			deltav -= nextStep;
			dropModule();
		}
		else{
			modules.top()->produceDeltav(deltav,pushLoad);
			break;
		};
	};
	return 0;
};
