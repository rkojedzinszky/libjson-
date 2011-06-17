#include <iostream>
#include <iomanip>
#include <json/ibool.hpp>

namespace JSON
{

IBool::IBool(bool v) : value(v)
{
}

bool IBool::getBool() const
{
	return value;
}

bool IBool::operator==(const IValue &r) const
{
	return value == dynamic_cast<const IBool&>(r).value;
}

void IBool::toStream(std::ostream &o) const
{
	o << std::boolalpha << value;
}

void IBool::fromStream(std::istream &i)
{
	i >> std::boolalpha >> value;
}

IScalar *IBool::clone() const
{
	return new IBool(value);
}

}; // namespace JSON
