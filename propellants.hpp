#ifndef INC_propellants_HPP
#define INC_propellants_HPP

#include <string>

struct phase{
	double density;
	double transition;//down, e.g solid = 0K
	phase(){};
	phase(
		double i_density,
		double i_transition
	):
		density(i_density),
		transition(i_transition)
	{};
};

struct compound{
	phase liquid;
	phase solid;
	phase gas;
	std::string name;
};

class propellant{
private:
	compound chemical;
public:
	propellant(){
		chemical.name = "generic_propellant";
		chemical.liquid.density = 1000;
	};
//
	propellant(
		double i_density
	){
		chemical.name = "generic_propellant";
		chemical.liquid.density = i_density;
	};
//
	propellant(
		std::string i_name
	){
		chemical.name = i_name;
	};
//
	propellant(
		std::string i_name,
		double i_density
	){
		chemical.liquid.density = i_density;
		chemical.name = i_name;
	};
//
	propellant(
		std::string i_name,
		double i_density,
		double i_boilingPoint
	){
		chemical.liquid.density = i_density;
		chemical.name = i_name;
		chemical.gas.transition = i_boilingPoint;
	};
//
	propellant(
		std::string i_name,
		double i_density,
		double i_boilingPoint,
		double i_freezingPoint
		
	){
		chemical.liquid.density = i_density;
		chemical.name = i_name;
		chemical.gas.transition = i_boilingPoint;
		chemical.liquid.transition = i_freezingPoint;
	};
//info
	double density(){
		return chemical.liquid.density;
	};
};

#endif
