#ifndef INC_atmosphere_HPP
#define INC_atmosphere_HPP

struct atmosphereLayer{
	double ceiling;
	double basePressure;
	double baseTemperature;
	double temperatureGradient;

	double density(double altitude){
		return 666;//place holder
	};
};

class atmosphere{
private:
	std::vector<atmosphereLayer> layers;
public:
	double ceiling;
	double density(double altitude){
		if(altitude > ceiling){
			return 0;//vacuum
		};
		for(unsigned int i=layers.size()-1;altitude > layers[i].ceiling;i--){
			return layers[i].density(altitude);
		};
	};
};

#endif
