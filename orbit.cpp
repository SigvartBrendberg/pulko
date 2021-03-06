#include <iostream>
#include <cmath>

#include "state.hpp"

double ellipse(double gm,double radius,double periapsis,double apoapsis){
	return std::sqrt(gm*(2/radius - 2/(apoapsis+periapsis)));
};
double transferCost(orbit* origin,orbit* target){
	try{
		if(origin->gm != target->gm){
			throw 0;
		};
		double gm = origin->gm;
		double result = origin->escapeCost(origin->periapsis) + target->escapeCost(target->periapsis);
		//planar-spatial bifurcation
		if(
			(origin->inc == 0 && target->inc == 0)
			||
			(origin->inc == target->inc && origin->asc == target->asc)
		){
			if(origin->periapsis == origin->apoapsis){//circular origin
				double hohmannCost;
				if(origin->periapsis < target->periapsis){
					hohmannCost =
						ellipse(
							gm,
							origin->periapsis,
							origin->periapsis,
							target->apoapsis
						)
						- origin->speed(origin->periapsis)
						+ target->speed(target->apoapsis)
						- ellipse(
							gm,
							target->apoapsis,
							origin->periapsis,
							target->apoapsis
						);
				}
				else{
					hohmannCost =
						- ellipse(
							gm,
							origin->periapsis,
							target->periapsis,
							origin->periapsis
						)
						- target->speed(target->periapsis)
						+ origin->speed(origin->periapsis)
						+ ellipse(
							gm,
							target->periapsis,
							target->apoapsis,
							origin->periapsis
						);
				};
				if(hohmannCost < result){
					result = hohmannCost;
				};
			}
			else if(target->periapsis == target->apoapsis){//target is circular but not origin
			}
			else{//neither target nor origin is circular
				if(
					fmod(origin->arg + origin->asc,2*M_PI)
					==
					fmod(target->arg + target->asc,2*M_PI)
				){//apsis line is parallel, FIXME because float
				}
				else{
				};
			};
		}//end planar
		else{
		}
		return result;
	}
	catch(int e){
		switch(e){
			case 0:
				std::cout << "not same system";
				break;
			default:
				std::cout << "an unknown transfer exception occured";
		};
		std::cout << std::endl;
		return -1;
	};
};
