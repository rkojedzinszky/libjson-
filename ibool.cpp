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

bool IBool::operator==(const IValue &r) const throw (std::bad_cast)
{
	return value == dynamic_cast<const IBool&>(r).value;
}

void IBool::toStream(std::ostream &o) const
{
	o << (value ? "true" : "false");
}

IScalar *IBool::clone() const
{
	return new IBool(value);
}

}; // namespace JSON
