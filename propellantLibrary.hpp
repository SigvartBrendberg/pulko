#include "propellant.hpp"

//propellant library

propellant fuel_NONE;//virtual oxidizer, used for monopropellant systems

//fuels:

propellant fuel_LH2(
	"liquid hydrogen",
	70.85,
	20,
	14
);
propellant fuel_RP1(
	"RP-1",
	806,//american RP-1 at 806, russian/soviet RP-1 like often 820-850 when cooled
	420,
	200
);

propellant fuel_CH4(
	"methane",
	424,
	111,
	89
);

propellant fuel_syntin(
	"syntin",
	851,//briefly used in soviet for higher density
	431,
	200//value from RP-1
);

//oxidizers:

propellant fuel_LOX(
	"liquid oxygen",
	1141,
	90,
	64
);
propellant fuel_N2O4(
	"nitrogen tetroxide"
);
propellant fuel_H2O2(
	"hydrogen peroxide"
);
