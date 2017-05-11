#include <cstdlib>
#include <ctime>
#include <iostream>

#include "pulko.hpp"
#include "body.hpp"
#include "bodyLibrary.hpp"
#include "shell.hpp"

int main(){
	body MOUNT;
	initSystem(&MOUNT);
	std::cout << "checkpoint" << std::endl;
	std::cout << MOUNT.latestChild()->name << std::endl;
	std::srand(std::time(0));
	stuff();
	while(shell::eval()){};
	/*char wait;
	std::cin >> wait;*/
	return 0;
};
