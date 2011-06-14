#include <istring.hpp>

namespace JSON
{

IString::IString(const std::string &s) : value(s)
{
}

IString::operator std::string() const throw ()
{
	return value;
}

IScalar *IString::clone() const
{
	return new IString(value);
}

}; // namespace JSON
