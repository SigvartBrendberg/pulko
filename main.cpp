#include <cstdlib>
#include <ctime>

#include "pulko.hpp"
#include "body.hpp"
#include "maneuvers.hpp"

int main(){
	std::srand(std::time(0));
	body* systemMoutPoint = init_solarSystem();
	stuff();
	delete systemMoutPoint;
	return 0;
};
