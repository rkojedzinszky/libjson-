#ifndef JSON_IHASH_HPP
#define JSON_IHASH_HPP

#include <map>
#include <string>
#include <json/ivalue.hpp>

namespace JSON
{

class Value;

class IHash : public IValue
{
private:
	std::map<std::string, Value> hash;

public:
	Value &operator[](const std::string &f) throw ();
	size_t size() const throw ();

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
