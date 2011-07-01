#include <iostream>
#include <iomanip>

#include <json/ibool.hpp>

namespace JSON
{

bool IBool::getBool() const
{
	return value;
}

bool IBool::asBool() const
{
	return value;
}

int IBool::asInt() const
{
	return value ? 1 : 0;
}

long long IBool::asLong() const
{
	return value ? 1 : 0;
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

}; // namespace JSON
