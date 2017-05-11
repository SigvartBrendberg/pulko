#include <iostream>
#include <vector>
#include <cmath>

#include "module.hpp"

double module::getMass(){
/*	double totalStageMass = 0;
	for(int i=0;i<boosters.size();i++){
		totalStageMass += boosters[i]->getMass() * boosterSymetry[i];//we thrust the stage has kept track of its own mass
	};
	return totalStageMass;
	//wrong but useful
*/
	return mass;
};
double module::getThrust(){
	double totalStageThrust = 0;
	for(int i=0;i<boosters.size();i++){
		totalStageThrust += boosters[i]->getThrust() * boosterSymetry[i];
	};
	return totalStageThrust;
};
//actions
int module::addStage(stage* i_stage,int symetry){
	if(symetry < 1){
		std::cout << "invalid symetry" << std::endl;
		return 1;
	};
	boosters.push_back(i_stage);
	boosterSymetry.push_back(symetry);
	mass += symetry * i_stage->getMass();
	return 0;
};
bool module::dropBooster(){
	if(boosters.size() == 0){
		std::cout << "module has no stages" << std::endl;
		return 1;
	};
	mass -= boosters[boosters.size()-1]->getMass() * boosterSymetry[boosterSymetry.size()-1];//we pop because only the outermost stage can be dropped
	delete boosters[boosters.size()-1];
	boosters.pop_back();
	boosterSymetry.pop_back();
	return 0;
};
int module::produceDeltav(
	double deltav
){
	//TODO: connect to the stages
};
