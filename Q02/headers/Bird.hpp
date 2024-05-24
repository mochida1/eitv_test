#pragma once
#ifndef BIRD_HPP
# define BIRD_HPP

#include <iostream>

// definimos Bird como uma classe puramente virtual para que não seja instanciada.
class Bird {
private:
protected:
	std::string _birdName;
	std::string _food;
	int _flightDistance;
	std::string _song;
public:
	Bird(void);
	virtual ~Bird() = 0; // Destrutores têm sempre de ser declarados com virtual caso seja uma classe base
	void eat(void);
	void sing(void);
	void fly(void);
};

#endif // BIRD_HPP