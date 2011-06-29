#ifndef JSON_IOBJECT_HPP
#define JSON_IOBJECT_HPP

#include <map>
#include <string>

#include <json/value.hpp>

namespace JSON
{

class IObject : public IValue
{
private:
	std::map<std::string, Value> object;

public:
	Value &operator[](const std::string &f);
	Value keys() const;
	size_t erase(const std::string &f);
	size_t size() const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
