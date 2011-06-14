#include <json/inumeric.hpp>

namespace JSON
{

INumeric::INumeric(double v) : value(v)
{
}

INumeric::operator double() const
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
