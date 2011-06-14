#include <iinteger.hpp>

namespace JSON
{

IInteger::IInteger(int v) : value(v)
{
}

IInteger::operator int() const throw ()
{
	return value;
}

bool IInteger::operator==(const IValue &r) const throw (std::bad_cast)
{
	return value == dynamic_cast<const IInteger&>(r).value;
}

bool IInteger::operator<(const IValue &r) const throw (std::bad_cast)
{
	return value < dynamic_cast<const IInteger&>(r).value;
}

bool IInteger::operator<=(const IValue &r) const throw (std::bad_cast)
{
	return value <= dynamic_cast<const IInteger&>(r).value;
}

void IInteger::toStream(std::ostream &o) const
{
	o << value;
}

IScalar *IInteger::clone() const
{
	return new IInteger(value);
}

}; // namespace JSON
