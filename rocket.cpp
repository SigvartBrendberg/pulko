#include "rocket.hpp"

double rocket::getMass(){
		return mass;
};
double rocket::getThrust(){
	return stages.top()->getThrust();
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
bool rocket::dropStage(){
	if(!stages.empty()){
		stage* topp = stages.top();
		stages.pop();
		mass -= topp->getMass();
		delete topp;
		return false;
	};
	return true;
};
int rocket::produceDeltav(double deltav){
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
