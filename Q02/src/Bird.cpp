#include "Bird.hpp"

Bird::Bird(/* args */)
{
}

Bird::~Bird()
{
}

void Bird::eat(void){
	std::cout << this->_birdName + " eats some " << this->_food << std::endl;
}

void Bird::sing(void){
	std::cout << this->_birdName + " says " << this->_song << std::endl;
}

void Bird::fly(void) {
	std::cout << this->_birdName + " flies for " << this->_flightDistance << " meters" << std::endl;
}