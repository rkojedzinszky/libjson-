#include <json/ifixed.hpp>

namespace JSON
{

int IFixed::getInt() const
{
	return INumeric::get<int>(value);
}

unsigned IFixed::getUInt() const
{
	return INumeric::get<unsigned>(value);
}

long long IFixed::getLong() const
{
	return value;
}

unsigned long long IFixed::getULong() const
{
	return INumeric::get<unsigned long long>(value);
}

double IFixed::getDouble() const
{
	return INumeric::get<double>(value);
}

bool IFixed::asBool() const
{
	return value == 0 ? false : true;
}

int IFixed::asInt() const
{
	return INumeric::get<int>(value);
}

unsigned IFixed::asUInt() const
{
	return INumeric::get<unsigned>(value);
}

long long IFixed::asLong() const
{
	return value;
}

unsigned long long IFixed::asULong() const
{
	return INumeric::get<unsigned long long>(value);
}

double IFixed::asDouble() const
{
	return INumeric::get<double>(value);
}

std::string IFixed::asString() const
{
	std::ostringstream o;

	o.precision(20);
	o << value;

	return o.str();
}

bool IFixed::operator==(const IValue &r) const
{
	return value == r.getLong();
}

bool IFixed::operator<(const IValue &r) const
{
	return value < r.getLong();
}

bool IFixed::operator<=(const IValue &r) const
{
	return value <= r.getLong();
}

void IFixed::toStream(std::ostream &o) const
{
	o << value;
}

}; // namespace JSON
