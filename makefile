pulko : pulko.o orbit.o state.o
	g++ -o pulko pulko.o state.o
pulko.o : pulko.cpp
	g++ -O2 -c pulko.cpp
orbit.o : orbit.cpp orbit.h
	g++ -O2 -c orbit.cpp
state.o  : state.cpp state.h
	g++ -O2 -c state.cpp
