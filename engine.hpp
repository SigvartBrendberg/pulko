#include <iostream>//debug

#include "basic_part.hpp"
#include "propellant.hpp"

struct engine : public basic_part{
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
		basic_part(0),
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
		basic_part(i_masse),
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
		basic_part(i_masse),
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
