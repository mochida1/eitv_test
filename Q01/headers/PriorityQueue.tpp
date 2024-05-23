#pragma once
#ifndef PRIORITYQUEUE_HPP
# define PRIORITYQUEUE_HPP

#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include "SomeObject.hpp"


template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
class SpecPriorityQueue : public std::priority_queue<T, Container, Compare> {
public:
	using iterator = typename Container::const_iterator;
	// find by priority
	iterator find(int value) const {
		return std::find_if( this->c.begin(), this->c.end(), [&value](const T& obj){ return obj.getPrioprity() == value; } );
	}

	// find by identifier 
	iterator find(const std::string& name) const {
		return std::find_if(this->c.begin(), this->c.end(), [&name](const T& obj) {
			return obj.getIdentifier() == name;
		});
	}

	// end method to get the end iterator of the underlying container
	iterator end() const {
		return this->c.end();
	}

	void remove(iterator it) {
		if (it != this->c.end()) {
			this->c.erase(it);
			std::make_heap(this->c.begin(), this->c.end(), this->comp);
		}
	}

	void print_all(void) const {
		// we need to make a deep copy of this to print and pop since it's underlying container is not sorted.
		auto copy = *this;
		while (!copy.empty()){
			std::cout << "[P=" << copy.top().getPrioprity() << "]:["  << copy.top().getIdentifier() << "], ";
			copy.pop();
		}
		std::cout << std::endl;
	}
};




#endif // PRIORITYQUEUE_HPP