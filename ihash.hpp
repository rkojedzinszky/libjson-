#ifndef IHASH_HPP
#define IHASH_HPP

#include <map>
#include <value.hpp>
#include <ivalue.hpp>
#include <string>

namespace JSON
{

class IHash : public IValue
{
private:
	std::map<std::string, Value> hash;
public:
	Value &operator[](const std::string &f) throw ();
	size_t size() const throw ();
};

}; // namespace JSON

#endif
