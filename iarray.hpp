#ifndef IARRAY_HPP
#define IARRAY_HPP

#include <vector>

namespace JSON
{

class IArray : public ValueBase
{
private:
	std::vector<Value> value;
public:
	Value &operator[](int idx) throw ();
	size_t size() const throw();
};

};

#endif
