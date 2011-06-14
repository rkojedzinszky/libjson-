#include <istring.hpp>
#include <util.hpp>

namespace JSON
{

IString::IString(const std::string &s) : value(s)
{
}

IString::operator const std::string&() const throw ()
{
	return value;
}

void IString::toStream(std::ostream &o) const
{
	stringtojsonstream(value, o);
}

IScalar *IString::clone() const
{
	return new IString(value);
}

}; // namespace JSON
