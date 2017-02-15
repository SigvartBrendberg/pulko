#ifndef INC_propellants_HPP
#define INC_propellants_HPP

#include <string>

struct propellant{
	double density;
	std::string name;
	double boilingPoint;//kelvin
	double freezingPoint;//kelvin
	propellant():
		name("generic_propellant"),
		density(1000),
		boilingPoint(350)
	{};
	propellant(
		double i_density
	):
		name("generic_propellant"),
		density(i_density),
		boilingPoint(350)
	{};
	propellant(
		std::string i_name
	):
		name(i_name),
		density(1000),
		boilingPoint(350)
	{}
	propellant(
		std::string i_name,
		double i_density
	):
		density(i_density),
		name(i_name),
		boilingPoint(350)
	{};
	propellant(
		std::string i_name,
		double i_density,
		double i_boilingPoint
	):
		density(i_density),
		name(i_name),
		boilingPoint(i_boilingPoint)
	{};
	propellant(
		std::string i_name,
		double i_density,
		double i_boilingPoint,
		double i_freezingPoint
		
	):
		density(i_density),
		name(i_name),
		boilingPoint(i_boilingPoint),
		freezingPoint(i_freezingPoint)
	{};
};

#endif
