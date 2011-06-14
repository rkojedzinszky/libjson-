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

IScalar *IInteger::clone() const
{
	return new IInteger(value);
}

}; // namespace JSON
