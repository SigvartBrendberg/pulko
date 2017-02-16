#ifndef INC_capsule_HPP
#define INC_capsule_HPP

#include <vector>

#include "cosmonaut.hpp"
#include "parts.hpp"

class capsule{
private:
	double ablator;
	double temperature;
	std::vector<cosmonaut*> crew;
public:
	~capsule(){
		for(unsigned int i=crew.size();i--;){
			delete crew[i];
		};
	};
	double friction;
	double mass;
	unsigned int crewCapacity;
};

class serviceModule{
private:
	std::vector<payload*> payloads;
	stage core;
public:
	~serviceModule(){
		for(unsigned int i=payloads.size();i--;){
			delete payloads[i];
		};
	};
	double getMass(){
		double mass = core.getMass();
		for(unsigned int i=payloads.size();i--;){
			mass += payloads[i]->mass;
		};
		return mass;
	};
};

#endif
