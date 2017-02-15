#include "body.hpp"
#include "state.hpp"
#include "parts.hpp"

class spacecraft{
private:
	unsigned long long timeStamp;
	orbit orb;
	ground gro;
	bool spaceMode;
	body* centralBody;
	rocket* hardware;
public:
	spacecraft():
		spaceMode(false)
	{};
};
