#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>

#include <json/inumeric.hpp>

namespace JSON
{

INumeric::INumeric(long long v) : value(static_cast<double>(v))
{
	if (static_cast<long long>(value) != v) {
		std::ostringstream o;
		o << "INumeric::INumeric(): long long value " << v << " could not be stored without loss";
		throw std::domain_error(o.str());
	}
}

INumeric::INumeric(double v) : value(v)
{
}

int INumeric::getInt() const
{
	int r = static_cast<int>(value);

	if (static_cast<double>(r) != value) {
		std::ostringstream o;
		o.precision(20);
		o << "JSON::INumeric::getInt(): " << value << " cannot be converted";
		throw std::domain_error(o.str());
	}

	return r;
}

long long INumeric::getLong() const
{
	long long r = static_cast<long long>(value);

	if (static_cast<double>(r) != value) {
		std::ostringstream o;
		o.precision(20);
		o << "JSON::INumeric::getLong(): " << value << " cannot be converted";
		throw std::domain_error(o.str());
	}

	return r;
}

double INumeric::getDouble() const
{
	return value;
}

bool INumeric::asBool() const
{
	return value == 0 ? false : true;
}

int INumeric::asInt() const
{
	return getInt();
}

long long INumeric::asLong() const
{
	return getLong();
}

double INumeric::asDouble() const
{
	return value;
}

std::string INumeric::asString() const
{
	std::ostringstream o;

	o.precision(20);
	o << value;

	return o.str();
}

bool INumeric::operator==(const IValue &r) const
{
	return value == dynamic_cast<const INumeric&>(r).value;
}

bool INumeric::operator<(const IValue &r) const
{
	return value < dynamic_cast<const INumeric&>(r).value;
}

bool INumeric::operator<=(const IValue &r) const
{
	return value <= dynamic_cast<const INumeric&>(r).value;
}

void INumeric::toStream(std::ostream &o) const
{
	o << value;
}

void INumeric::fromStream(std::istream &i)
{
	i >> value;
}

}; // namespace JSON
