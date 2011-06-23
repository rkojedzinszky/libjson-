#include <iostream>
#include <iomanip>
#include <json/inumeric.hpp>
#include <stdexcept>
#include <sstream>

#define DOUBLE_MANTISSA_BITS	52
#define DOUBLE_LONG_MAX		(1LL << (DOUBLE_MANTISSA_BITS + 1))

namespace JSON
{

INumeric::INumeric(long long v) : value(v)
{
	if (v < -DOUBLE_LONG_MAX || v > DOUBLE_LONG_MAX) {
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
	int r = value;

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
	long long r = value;

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

IScalar *INumeric::clone() const
{
	return new INumeric(value);
}

}; // namespace JSON
