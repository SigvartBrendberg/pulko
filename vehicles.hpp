#include <vector>

#include "spacecraft.hpp"
#include "capsule.hpp"

class manned{
private:
public:
	spacecraft* craft;
	std::vector<capsule*> quarters;
};

class probe{
private:
public:
	spacecraft* craft;
};
