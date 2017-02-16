#ifndef INC_compounds_HPP
#define INC_compounds_HPP

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

#endif
