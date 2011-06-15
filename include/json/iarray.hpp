#ifndef JSON_IARRAY_HPP
#define JSON_IARRAY_HPP

#include <json/ivalue.hpp>
#include <deque>

namespace JSON
{

class Value;

class IArray : public IValue
{
private:
	std::deque<Value> value;

public:
	Value &operator[](int idx) throw ();
	size_t size() const throw();

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
