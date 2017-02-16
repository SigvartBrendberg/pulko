#ifndef INC_parts_HPP
#define INC_parts_HPP

#include "propellants.hpp"

struct payload{
	double mass;
	payload():mass(0){};
	payload(
		double i_mass
	):
		mass(i_mass)
	{};
};

struct engine{
	double mass;
	double vel;
	double thrust;
	double air_vel;
	double air_thrust;
	propellant* fuel;
	propellant* oxidizer;
	double oxiPerFuel;
	bool dropable;
	bool hasPropellant;
	bool needsOxidizer;

	engine():
		mass(0),
		vel(0),
		thrust(0),
		air_vel(0),
		air_thrust(0),
		oxiPerFuel(0),
		dropable(false),
		hasPropellant(false),
		needsOxidizer(false)
	{};
	engine(
		double i_masse,
		double i_vel,
		double i_thrust,
		propellant* i_fuel,
		propellant* i_oxidizer,
		double i_oxiPerFuel
	):
		mass(i_masse),
		vel(i_vel),
		thrust(i_thrust),
		fuel(i_fuel),
		oxidizer(i_oxidizer),
		oxiPerFuel(i_oxiPerFuel),
		dropable(true),
		hasPropellant(false),
		needsOxidizer(true)
	{};
	engine(
		double i_masse,
		double i_vel,
		double i_thrust,
		double i_air_vel,
		double i_air_thrust,
		propellant* i_fuel,
		propellant* i_oxidizer,
		double i_oxiPerFuel
	):
		mass(i_masse),
		vel(i_vel),
		thrust(i_thrust),
		air_vel(i_air_vel),
		air_thrust(i_air_vel),
		fuel(i_fuel),
		oxidizer(i_oxidizer),
		oxiPerFuel(i_oxiPerFuel),
		dropable(true),
		hasPropellant(false),
		needsOxidizer(true)
	{};
	~engine(){
		std::cout << "bye bye engine" << std::endl;//DEBUG
	};
};

struct tank{
	double dead;
	double volume;
	propellant* prop;
	double propMass;
	bool dropable;

	tank():
		dead(0),
		volume(0),
		propMass(0),
		dropable(true)
	{};
	tank(
		double i_dead,
		double i_volume,
		propellant* i_prop,
		double i_propMass
	):
		dead(i_dead),
		volume(i_volume),
		prop(i_prop),
		propMass(i_propMass),
		dropable(true)
	{};
//info
	double getCapacity(){
		return volume/prop->density();
	};
};

class stage{
private:
	std::vector<tank*> tanks;
	std::vector<engine*> engines;
	double mass;
public:
//constructors
	stage() : mass(0){};
//destructors
	~stage(){
		std::cout << "bye bye stage" << std::endl;//DEBUG
		for(unsigned int i = 0; i < tanks.size();i++){
			delete tanks[i];
		};
		for(unsigned int i = 0; i < engines.size();i++){
			delete engines[i];
		};
	};
//internal management
	void scanEngines(){
		/*
Checks what engines have propellant available.
Call when a tank is empty or dropped
		*/
		for(unsigned int i = engines.size();i--;){
			for(unsigned int j = tanks.size();j--;){
				if(engines[i]->fuel == tanks[j]->prop){
					engines[i]->hasPropellant = true;
					break;
				};
			};
			if(
				engines[i]->hasPropellant
				&& engines[i]->needsOxidizer
			){
				engines[i]->hasPropellant = false;
				for(unsigned int j = tanks.size();j--;){
					if(engines[i]->oxidizer == tanks[j]->prop){
						engines[i]->hasPropellant = true;
						break;
					};
				};	
			};
		};
	};
//info
	double getMass(){
		return mass;
	};
	double detectDeltav(double pushLoad){
		return 0;//plasshaldar
	};
	double getThrust(){
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
	int addEngine(engine* i_engine){
		engines.push_back(i_engine);
		mass += i_engine->mass;
		scanEngines();//check if it can get propellant
		return 0;
	};
	int dropEngine(unsigned int engineIndex){
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
	int transferPropellant(
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
	int produceDeltav(double pushLoad){
		return 0;//plasshaldar
	};
};

class rocket{
private:
	std::vector<stage*> stages;
	std::vector<payload*> payloads;
	double mass;
public:
//variables
	std::string name;
//constructors
	rocket():
		name("unnamed"),
		mass(0)
	{};
//destructors
	~rocket(){
		std::cout << name << " has been destroyed" << std::endl;
		for(unsigned int i = 0; i < stages.size();i++){
			delete stages[i];
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
		return stages[stages.size()]->getThrust();
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
	int dropStage(){
		if(stages.size()){
			mass -= stages[stages.size() - 1]->getMass();
			delete stages[stages.size() - 1];
			stages.pop_back();
			return 0;
		};
		return 0;
	};
	int produceDeltav(double deltav){
		while(deltav > 0){
			if(stages.size() == 0){
				return 1;//not enough deltav in stages to reach target value
			};
			unsigned int inUse = stages.size() - 1;
			double pushLoad = mass - stages[inUse]->getMass();
			double nextStep = stages[inUse]->detectDeltav(pushLoad);
			if(deltav > nextStep){
				deltav -= nextStep;
				dropStage();
			}
			else{
				stages[inUse]->produceDeltav(pushLoad);
				break;
			};
		};
		return 0;
	};
};

#endif
