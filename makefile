pulko : main.o pulko.o orbit.o state.o bodyLibrary.o descent.o ascent.o
	g++ -o pulko main.o pulko.o orbit.o state.o bodyLibrary.o descent.o ascent.o

main.o : main.cpp pulko.hpp body.hpp
	g++ -O3 -c main.cpp

pulko.o : pulko.cpp propellantLibrary.hpp parts.hpp engines.hpp state.hpp orbit.hpp vehicles.hpp capsule.hpp cosmonaut.hpp skill.hpp spacecraft.hpp parts.hpp propellants.hpp compounds.hpp
	g++ -O3 -c pulko.cpp
orbit.o : orbit.cpp
	g++ -O3 -c orbit.cpp
state.o : state.cpp state.hpp
	g++ -O3 -c state.cpp
bodyLibrary.o : bodyLibrary.cpp body.hpp atmosphere.hpp compounds.hpp
	g++ -O3 -c bodyLibrary.cpp
descent.o : descent.cpp spacecraft.hpp parts.hpp propellants.hpp compounds.hpp state.hpp orbit.hpp
	g++ -O3 -c descent.cpp
ascent.o : ascent.cpp spacecraft.hpp parts.hpp propellants.hpp compounds.hpp
	g++ -O3 -c ascent.cpp

