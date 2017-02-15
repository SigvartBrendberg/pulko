class ground{
private:
public:
	double gm;
	double radius;
	double hori;
	double vert;
	double longitude;
	double latitude;
	double direction;
	ground():
		radius(0),
		hori(0),
		vert(0),
		longitude(0),
		latitude(0),
		direction(0)
	{};
};

class orbit{
private:
public:
	double gm;
	double periapsis;
	double apoapsis;
	double inc;
	double arg;
	double asc;
	double ano;
	orbit():
		gm(1),
		apoapsis(0),
		periapsis(0),
		inc(0),
		arg(0),
		asc(0),
		ano(0)
	{};
	orbit(
		double i_gm,
		double i_periapsis,
		double i_apoapsis,
		double i_inc,
		double i_arg,
		double i_asc,
		double i_ano
	):
		gm(i_gm),
		apoapsis(i_apoapsis),
		periapsis(i_periapsis),
		inc(i_inc),
		arg(i_arg),
		asc(i_asc),
		ano(i_ano)
	{};
//unlisted properties
	double radius(){
		return 2*apoapsis*periapsis/((apoapsis-periapsis)*std::cos(ano) + apoapsis + periapsis);
		//(2 A P)/((A - P) cos(u) + A + P)
	};
	double semi(){
		return (periapsis + apoapsis)/2;
	};
	double eccentricity(){
		return (apoapsis-periapsis)/(periapsis + apoapsis);
	};
	double speed(){
		return std::sqrt(
			gm*(2/radius() - 2/(apoapsis + periapsis))
		);
	};
	double speed(double distance){
		return std::sqrt(
			gm*(2/distance - 2/(apoapsis + periapsis))
		);
	};
	double horisontalSpeed(){
		return speed(periapsis)*periapsis/radius();
	};
	double horisontalSpeed(double distance){
		return speed(periapsis)*periapsis/distance;
	};
//info
	double escapeCost(double distance){
		return std::sqrt(2*gm/distance) - std::sqrt(gm*(2/distance - 2/(apoapsis+periapsis)));
	};
};

orbit groundToOrbit(ground* initial);

ground orbitToGround(orbit* initial);
