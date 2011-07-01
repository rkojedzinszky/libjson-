#include <sstream>
#include <stdexcept>
#include <typeinfo>

#include <json/istring.hpp>
#include <json/util.hpp>

namespace JSON
{

const std::string &IString::getString() const
{
	return value;
}

bool IString::asBool() const
{
	return value != "" && value != "0";
}

template <typename T>
inline T _parse(const std::string &s)
{
	T ret;
	std::istringstream is(s);
	is >> ret;

	if (!is.eof()) {
		std::ostringstream e;
		e << s << " cannot be converted to " << typeid(T).name();
		throw std::domain_error(e.str());
	}

	return ret;
}

int IString::asInt() const
{
	return _parse<int>(value);
}

long long IString::asLong() const
{
	return _parse<long long>(value);
}

double IString::asDouble() const
{
	return _parse<double>(value);
}

std::string IString::asString() const
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

}; // namespace JSON
