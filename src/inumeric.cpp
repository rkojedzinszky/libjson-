#include <json/ifixed.hpp>
#include <json/ifloat.hpp>
#include <cmath>

namespace JSON
{

IValue::Type INumeric::type() const
{
	return JSON_NUMBER;
}

INumeric * INumeric::fromStream(std::istream &is)
{
	double v;

	is >> v;

	double i;
	double f = ::modf(v, &i);

	if (f == 0.0)
		return new IFixed(INumeric::get<long long>(i));
	else
		return new IFloat(v);
}

}; // namespace JSON
