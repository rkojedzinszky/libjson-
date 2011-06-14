#ifndef JSON_IARRAY_HPP
#define JSON_IARRAY_HPP

#include <vector>
#include <json/value.hpp>
#include <json/ivalue.hpp>

namespace JSON
{

class IArray : public IValue
{
private:
	std::vector<Value> value;
public:
	Value &operator[](int idx) throw ();
	size_t size() const throw();

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
