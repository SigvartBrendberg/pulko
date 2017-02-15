#ifndef INC_propellants_HPP
#define INC_propellants_HPP

#include <string>

struct propellant{
	double density;
	std::string name;
	propellant():
		name("generic_propellant"),
		density(0)
	{};
	propellant(
		double i_density,
		std::string i_name
	):
		density(i_density),
		name(i_name)
	{};
};

propellant fuel_NONE;//virtual oxidizer, used for monopropellant systems

#endif
