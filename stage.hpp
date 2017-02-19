#ifndef INC_stage_HPP
#define INC_stage_HPP

#include <iostream>
#include <vector>

#include "engine.hpp"

class tank : basic_part{
public:
	double volume;
	propellant* prop;
	double propMass;
	bool dropable;

	tank():
		basic_part(0),
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
		basic_part(i_dead),
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
	unsigned int scanEngines();
//info
	double getMass();
	double detectDeltav(
		double pushLoad
	);
	double getThrust();
//actions
	int addEngine(
		engine* i_engine
	);
	int dropEngine(
		unsigned int engineIndex
	);
	int transferPropellant(
		unsigned int originIndex,
		unsigned int targetIndex,
		double amount
	);
	int produceDeltav(
		double deltav,
		double pushLoad
	);
};

#endif
