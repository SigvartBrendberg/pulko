pulko : pulko.o orbit.o state.o
	g++ -o pulko pulko.o state.o

pulko.o : pulko.cpp propellantLibrary.hpp parts.hpp engines.hpp state.hpp orbit.hpp spacecraft.hpp bodyLibrary.hpp
	g++ -O2 -c pulko.cpp
orbit.o : orbit.cpp orbit.hpp
	g++ -O2 -c orbit.cpp
state.o : state.cpp state.hpp
	g++ -O2 -c state.cpp
bodyLibrary.o : bodyLibrary.cpp body.hpp
	g++ -O2 -c bodyLibrary.cpp
