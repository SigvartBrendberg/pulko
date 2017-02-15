pulko : main.o pulko.o orbit.o state.o bodyLibrary.o
	g++ -o pulko main.o pulko.o state.o bodyLibrary.o

main.o : main.cpp pulko.hpp body.hpp
	g++ -O3 -c main.cpp

pulko.o : pulko.cpp propellantLibrary.hpp parts.hpp engines.hpp state.hpp orbit.hpp spacecraft.hpp
	g++ -O3 -c pulko.cpp
orbit.o : orbit.cpp
	g++ -O3 -c orbit.cpp
state.o : state.cpp state.hpp
	g++ -O3 -c state.cpp
bodyLibrary.o : bodyLibrary.cpp body.hpp
	g++ -O3 -c bodyLibrary.cpp
