#include <iostream>
#include <vector>
#include <cmath>

#include "stage.hpp"

unsigned int stage::scanEngines(){
		/*
Checks what engines have propellant available.
Call when a tank is empty or dropped
		*/
	unsigned int any = 0;
	for(unsigned int i = engines.size();i--;){
		for(unsigned int j = tanks.size();j--;){
			if(engines[i]->fuel == tanks[j]->prop){
				engines[i]->hasPropellant = true;
				break;
			};
		};//checks if any tank has the appropiate fuel
		if(engines[i]->needsOxidizer){
			any++;
		}
		else if(
			engines[i]->hasPropellant
		){
			engines[i]->hasPropellant = false;
			for(unsigned int j = tanks.size();j--;){
				if(engines[i]->oxidizer == tanks[j]->prop){
					engines[i]->hasPropellant = true;
					any++;
					break;
				};
			};	
		};
	};
	return any;
};
//info
double stage::getMass(){
	return mass;
};
double stage::detectDeltav(double pushLoad){
	double deltav = 0;
	double lostMass = 0;
	while(scanEngines()){
		unsigned int indeks = 0;
		double vel = 0;
		for(unsigned int i=0;i<engines.size();i++){
			if(engines[i]->hasPropellant && engines[i]->vel > vel){
				indeks = i;
				vel = engines[i]->vel;
			};
		};
		propellant* fuel = engines[indeks]->fuel;
		propellant* oxid = engines[indeks]->oxidizer;
		double limitedFuel = 0;//amount of proper fuel
		double limitedOxidizer = 0;//amount of proper oxidizer
		for(unsigned int i=0;i<tanks.size();i++){
			if(tanks[i]->prop == fuel){
				limitedFuel += tanks[i]->propMass;
			}
			else if(tanks[i]->prop == oxid){
				limitedOxidizer += tanks[i]->propMass;
			};
		};
		double expMass;
		if(limitedOxidizer < limitedFuel * engines[indeks]->oxiPerFuel){//find the limiting factor
			expMass = limitedOxidizer * (1+1/engines[indeks]->oxiPerFuel);
		}
		else{
			expMass = limitedFuel * (1+engines[indeks]->oxiPerFuel);
		};
		deltav += std::log((mass + pushLoad - lostMass)/(mass + pushLoad - expMass - lostMass))*vel;
		lostMass += expMass;
	};
	return deltav;
};
double stage::getThrust(){
	scanEngines();
	double thrust;
	for(unsigned int i = engines.size();i--;){
		if(engines[i]->hasPropellant){
			thrust += engines[i]->thrust;//no compensation for air pressure at the moment
		};
	};
	return thrust;
};
//actions
int stage::addEngine(engine* i_engine){
	//TODO engines must be symetrical clusters
	engines.push_back(i_engine);
	mass += i_engine->mass;
	scanEngines();//check if it can get propellant
	return 0;
};
int stage::dropEngine(unsigned int engineIndex){
	try{
		if(engines.size() <= engineIndex){
			throw 0;
		};
		mass -= engines[engineIndex]->mass;
		engines.erase(engines.begin()+engineIndex);
		return 0;
	}
	catch(int e){
		switch(e){
			case 0:
				std::cout << "no such engine";
				break;
			default:
				std::cout << "an unknown engine dropping exception occured";
		};
		std::cout << std::endl;
		return 1;
	};
};
int stage::transferPropellant(
	unsigned int originIndex,
	unsigned int targetIndex,
	double amount
){
	try{
		if(originIndex == targetIndex){
			throw 0;
		};
		if(tanks.size() <= originIndex){
			throw 1;
		};
		if(tanks.size() <= targetIndex){
			throw 2;
		};
		if(tanks[originIndex]->propMass < amount){
			throw 3;
		};
		if(
			tanks[targetIndex]->getCapacity() - tanks[targetIndex]->propMass
			< amount
		){
			throw 4;
		};
		if(
			tanks[targetIndex]->propMass != 0
			&& tanks[originIndex]->prop != tanks[targetIndex]->prop
		){
			throw 5;
		};
		tanks[originIndex]->propMass -= amount;
		tanks[targetIndex]->propMass += amount;
		tanks[targetIndex]->prop = tanks[originIndex]->prop;
		return 0;
	}
	catch(int e){
		switch(e){
			case 0:
				std::cout << "target tank is orgin tank";
				break;
			case 1:
				std::cout << "no such origin tank";
				break;
			case 2:
				std::cout << "no such target tank";
				break;
			case 3:
				std::cout << "not enough propellant to transfer";
				break;
			case 4:
				std::cout << "not enough storage capacity at target";
				break;
			case 5:
				std::cout << "propellant mixing";
				break;
			default:
				std::cout << "an unknown propellant exception occured";
		};
		std::cout << std::endl;
		return 1;
	};
};
int stage::produceDeltav(double deltav,double pushLoad){
	while(scanEngines()){
		unsigned int indeks = 0;
		double vel = 0;
		for(unsigned int i=0;i<engines.size();i++){
			if(engines[i]->hasPropellant && engines[i]->vel > vel){
				indeks = i;
				vel = engines[i]->vel;
			};
		};
		propellant* fuel = engines[indeks]->fuel;
		propellant* oxid = engines[indeks]->oxidizer;
		double limitedFuel = 0;//amount of proper fuel
		double limitedOxidizer = 0;//amount of proper oxidizer
		double oxiPerFuel = engines[indeks]->oxiPerFuel;
		for(unsigned int i=0;i<tanks.size();i++){
			if(tanks[i]->prop == fuel){
				limitedFuel += tanks[i]->propMass;
			}
			else if(tanks[i]->prop == oxid){
				limitedOxidizer += tanks[i]->propMass;
			};
		};
		double expMass;
		if(limitedOxidizer < limitedFuel * oxiPerFuel){//find the limiting factor
			expMass = limitedOxidizer * (1+1/oxiPerFuel);
		}
		else{
			expMass = limitedFuel * (1+oxiPerFuel);
		};
		double testDeltav = std::log((mass + pushLoad)/(mass + pushLoad - expMass))*vel;
		if(testDeltav > deltav){
			expMass = (mass + pushLoad)/std::exp(testDeltav/vel) - mass - pushLoad;
			limitedFuel = expMass/(1+oxiPerFuel);
			limitedOxidizer = limitedFuel * oxiPerFuel;
		}
		else{
			deltav -= testDeltav;
		};
		mass -= expMass;
		for(unsigned int i=0;i<tanks.size();i++){
			if(tanks[i]->prop == fuel){
				if(limitedFuel > tanks[i]->propMass){
					limitedFuel -= tanks[i]->propMass;
					tanks[i]->propMass = 0;
				}
				else{
					tanks[i]->propMass -= limitedFuel;
					break;
				};
			};
		};
		for(unsigned int i=0;i<tanks.size();i++){
			if(tanks[i]->prop == oxid){
				if(limitedOxidizer > tanks[i]->propMass){
					limitedOxidizer -= tanks[i]->propMass;
					tanks[i]->propMass = 0;
				}
				else{
					tanks[i]->propMass -= limitedOxidizer;
					break;
				};
			};
		};
		if(testDeltav > deltav){
			return 0;
		};
	};
	return 1;//no error detection though...
};
