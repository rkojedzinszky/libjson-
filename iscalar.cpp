#include "base.hpp"

nullValue::nullValue() : std::runtime_error("nullValue exception")
{
}

IScalar::IScalar() : null(true)
{
}

IScalar::IScalar(const std::string &s) : null(false), value(s)
{
}

IScalar::IScalar(const IScalar &s) : null(s.null), value(s.value)
{
}

const std::string &IScalar::str() const throw (nullValue)
{
	if (null)
		throw nullValue();
	return value;
}

bool IScalar::isNull() const throw ()
{
	return null;
}
