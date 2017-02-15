pulko : pulko.o
	g++ -o pulko pulko.o
pulko.o : pulko.cpp
	g++ -O2 -c pulko.cpp
