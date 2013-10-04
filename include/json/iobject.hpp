#ifndef JSON_IOBJECT_HPP
#define JSON_IOBJECT_HPP

#include <map>
#include <string>

#include <json/ivalue.hpp>

namespace JSON
{

class IObject : public IValue
{
private:
	Object value;

public:
	// return type info
	Type type() const;

	// clone
	IObject* clone() const;

	Object &object();

	size_t size() const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
