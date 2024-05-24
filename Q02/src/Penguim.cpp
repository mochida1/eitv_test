#include "Penguim.hpp"

Penguim::Penguim(/* args */) {
	this->_birdName = "Penguim";
	this->_food = "fish";
	this->_flightDistance = 0;
	this->_song = "!!!!";
}

Penguim::~Penguim()
{
}

void Penguim::fly(void){
	std::cout << "Penguins don't fly. They can swim really well though" << std::endl;
}