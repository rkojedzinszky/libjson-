#include "scalar.hpp"

nullValue::nullValue() : std::runtime_error("nullValue exception")
{
}

Scalar::Scalar() : null(true)
{
}

Scalar::Scalar(const std::string &s) : null(false), value(s)
{
}

Scalar::Scalar(const Scalar &s) : null(s.null), value(s.value)
{
}

const std::string &Scalar::str() const throw (nullValue)
{
	if (null)
		throw nullValue();
	return value;
}

bool Scalar::isNull() const throw ()
{
	return null;
}
