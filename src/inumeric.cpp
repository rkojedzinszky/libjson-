#include <iostream>
#include <iomanip>
#include <json/inumeric.hpp>
#include <stdexcept>
#include <sstream>

#define DOUBLE_MANTISSA_BITS	52
#define DOUBLE_LONG_MAX		(1LL << (DOUBLE_MANTISSA_BITS + 1))

namespace JSON
{

INumeric::INumeric(double v) : value(v)
{
}

INumeric::INumeric(long long v) : value(v)
{
	if (v < -DOUBLE_LONG_MAX || v > DOUBLE_LONG_MAX) {
		std::ostringstream o;
		o << "INumeric::INumeric(): long long value " << v << " could not be stored without loss";
		throw std::domain_error(o.str());
	}
}

double INumeric::getDouble() const
{
	return value;
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
