pulko : main.o pulko.o orbit.o state.o bodyLibrary.o descent.o ascent.o stage.o rocket.o
	g++ -o pulko main.o pulko.o orbit.o state.o bodyLibrary.o descent.o ascent.o stage.o rocket.o

main.o : main.cpp
	g++ -O3 -c main.cpp

pulko.o : pulko.cpp
	g++ -O3 -c pulko.cpp
orbit.o : orbit.cpp
	g++ -O3 -c orbit.cpp
state.o : state.cpp
	g++ -O3 -c state.cpp
bodyLibrary.o : bodyLibrary.cpp
	g++ -O3 -c bodyLibrary.cpp
descent.o : descent.cpp
	g++ -O3 -c descent.cpp
ascent.o : ascent.cpp
	g++ -O3 -c ascent.cpp
stage.o : stage.cpp
	g++ -O3 -c stage.cpp
rocket.o : rocket.cpp
	g++ -O3 -c rocket.cpp
