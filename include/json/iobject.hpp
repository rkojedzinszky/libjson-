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
	Object &object();

	bool isNull() const;

	size_t size() const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
