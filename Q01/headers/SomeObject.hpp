#pragma once
#ifndef SOMEOBJECT_HPP
# define SOMEOBJECT_HPP

#include <string>
#include <stdexcept>

class SomeObject
{
private:
	int _priority;
	std::string _identifier;
public:
	SomeObject(void);
	SomeObject(int priority, std::string identifier);
	~SomeObject();
	int getPrioprity(void) const;
	std::string getIdentifier(void) const;
};

struct cmp{
    	bool operator()(const SomeObject& left, const SomeObject& right) const {
        	return left.getPrioprity() > right.getPrioprity();
		}
	};

#endif // SOMEOBJECT_HPP