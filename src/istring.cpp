#include <json/istring.hpp>
#include <json/util.hpp>

namespace JSON
{

IString::IString(const std::string &s) : value(s)
{
}

IString::operator const std::string&() const
{
	return value;
}

bool IString::operator==(const IValue &r) const
{
	return value == dynamic_cast<const IString&>(r).value;
}

bool IString::operator<(const IValue &r) const
{
	return value < dynamic_cast<const IString&>(r).value;
}

bool IString::operator<=(const IValue &r) const
{
	return value <= dynamic_cast<const IString&>(r).value;
}

void IString::toStream(std::ostream &o) const
{
	stringtojsonstream(value, o);
}

void IString::fromStream(std::istream &i)
{
	jsonstringtostring(value, i);
}

IScalar *IString::clone() const
{
	return new IString(value);
}

}; // namespace JSON