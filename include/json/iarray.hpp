#ifndef JSON_IARRAY_HPP
#define JSON_IARRAY_HPP

#include <deque>

#include <json/ivalue.hpp>

namespace JSON
{

class IArray : public IValue
{
private:
	Array value;

public:
	explicit IArray(size_t n);

	// return type info
	Type type() const;

	// clone
	IArray* clone() const;

	Array& array();
	const Array& array() const;

	size_t size() const;

	void toStream(std::ostream& o) const;
	void fromStream(std::istream& i);
};

inline IArray::IArray(size_t n) : value(n)
{
}

}; // namespace JSON

#endif
