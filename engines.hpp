/*a library of example engines
mass
exhaust velocity
thrust
	air_vel
	air_thrust (both optional)
fuel
oxidizer
mixture ratio
*/
engine engine_F1(
	8400,
	2980,
	7770000,
	2580,
	6770000,
	&fuel_RP1,
	&fuel_LOX,
	2.27
);
engine engine_J2(
	1788.1,
	4130,
	1033100,
	2000,
	486200,
	&fuel_LH2,
	&fuel_LOX,
	5.5
);
engine engine_NERVA;
