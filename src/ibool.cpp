#include <iostream>
#include <iomanip>

#include <json/ibool.hpp>

namespace JSON
{

IValue::Type IBool::type() const
{
	return JSON_BOOL;
}

IBool* IBool::clone() const
{
	return new IBool(value);
}

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

unsigned IBool::asUInt() const
{
	return value ? 1 : 0;
}

long long IBool::asLong() const
{
	return value ? 1 : 0;
}

unsigned long long IBool::asULong() const
{
	return value ? 1 : 0;
}

std::string IBool::asString() const
{
	return value ? "true" : "false";
}

bool IBool::operator==(const IValue& r) const
{
	return value == r.getBool();
}

void IBool::toStream(std::ostream& o) const
{
	o << std::boolalpha << value;
}

void IBool::fromStream(std::istream& i)
{
	i >> std::boolalpha >> value;
}

}; // namespace JSON
