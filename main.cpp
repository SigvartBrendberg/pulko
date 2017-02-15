#include "pulko.hpp"
#include "body.hpp"
#include "maneuvers.hpp"

int main(){
	body* systemMoutPoint = init_solarSystem();
	stuff();
	delete systemMoutPoint;
	return 0;
};
