#include "base.hpp"

namespace JSON
{

Value &IArray::operator[](int idx) throw ()
{
	if (idx >= value.size()) {
		value.resize(idx+1);
	}

	return value[idx];
}

size_t IArray::size() const throw()
{
	return value.size();
}

};
