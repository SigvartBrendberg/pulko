#include <vector>

#include "spacecraft.hpp"
#include "capsule.hpp"

class manned{
private:
public:
	spacecraft* craft;
	std::vector<capsule*> quarters;
	~manned(){
		for(unsigned int i=quarters.size();i--;){
			delete quarters[i];
		};
	};
};

class probe{
private:
public:
	spacecraft* craft;
};
