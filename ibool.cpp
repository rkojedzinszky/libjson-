#include <ibool.hpp>

namespace JSON
{

IBool::IBool(bool v) : value(v)
{
}

IBool::operator bool() const throw ()
{
	return value;
}

IScalar *IBool::clone() const
{
	return new IBool(value);
}

}; // namespace JSON
