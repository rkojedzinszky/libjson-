#include <iarray.hpp>

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

void IArray::toStream(std::ostream &o) const
{
	o << "[";

	for (std::vector<Value>::const_iterator I = value.begin(); I != value.end(); I++) {
		if (I != value.begin()) {
			o << ",";
		}

		I->toStream(o);
	}

	o << "]";
}

}; // namespace JSON
