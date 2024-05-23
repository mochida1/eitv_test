#include "SomeObject.hpp"

SomeObject::SomeObject(void) : _priority(20), _identifier(""){
}

SomeObject::SomeObject(int priority, std::string identifier) {
	if (priority < 1 || priority > 20)
		throw std::runtime_error("Critical error: Priority out of range.");
	this->_priority = priority;
	this->_identifier = identifier; 
	return;
}


SomeObject::~SomeObject() {
	return ;
}

int SomeObject::getPrioprity(void) const {
	return this->_priority;
}

std::string SomeObject::getIdentifier(void) const{
	return this->_identifier;
}