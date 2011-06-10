#include "array.hpp"

Value &Array::operator[](int idx) throw ()
{
	if (idx >= value.size())
		value.resize(idx+1);

	return value[idx];
}
