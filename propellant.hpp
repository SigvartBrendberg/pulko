#ifndef INC_propellant_HPP
#define INC_propellant_HPP

#include <string>

#include "compounds.hpp"

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
