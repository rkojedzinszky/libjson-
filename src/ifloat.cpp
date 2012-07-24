#include <json/ifloat.hpp>

namespace JSON
{

int IFloat::getInt() const
{
	return INumeric::get<int>(value);
}

unsigned IFloat::getUInt() const
{
	return INumeric::get<unsigned>(value);
}

long long IFloat::getLong() const
{
	return INumeric::get<long long>(value);
}

unsigned long long IFloat::getULong() const
{
	return INumeric::get<unsigned long long>(value);
}

double IFloat::getDouble() const
{
	return value;
}

bool IFloat::asBool() const
{
	return (value == 0.0 || value == -0.0) ? false : true;
}

int IFloat::asInt() const
{
	return INumeric::get<int>(value);
}

unsigned IFloat::asUInt() const
{
	return INumeric::get<unsigned>(value);
}

long long IFloat::asLong() const
{
	return INumeric::get<long long>(value);
}

unsigned long long IFloat::asULong() const
{
	return INumeric::get<unsigned long long>(value);
}

double IFloat::asDouble() const
{
	return value;
}

std::string IFloat::asString() const
{
	std::ostringstream o;

	o.precision(20);
	o << value;

	return o.str();
}

bool IFloat::operator==(const IValue &r) const
{
	return value == r.getDouble();
}

bool IFloat::operator<(const IValue &r) const
{
	return value < r.getDouble();
}

bool IFloat::operator<=(const IValue &r) const
{
	return value <= r.getDouble();
}

void IFloat::toStream(std::ostream &o) const
{
	o << value;
}

}; // namespace JSON
