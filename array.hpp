#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include "base.hpp"

class Array : public ValueBase {
	private:
		std::vector<Value> value;
	public:
		Value &operator[](int idx) throw ();
};

#endif
