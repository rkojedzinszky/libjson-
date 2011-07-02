#include <json/inumeric.hpp>

namespace JSON
{

template <typename T>
T INumeric::get() const
{
	T r = static_cast<T>(value);

	if (!numbers_equal(r, value)) {
		std::ostringstream o;
		o.precision(20);
		o << __PRETTY_FUNCTION__ << ": " << value << " cannot be stored without loss";
		throw std::domain_error(o.str());
	}

	return r;
}

int INumeric::getInt() const
{
	return get<int>();
}

unsigned INumeric::getUInt() const
{
	return get<unsigned>();
}

long long INumeric::getLong() const
{
	return get<long long>();
}

unsigned long long INumeric::getULong() const
{
	return get<unsigned long long>();
}

double INumeric::getDouble() const
{
	return value;
}

bool INumeric::asBool() const
{
	return value == 0 ? false : true;
}

int INumeric::asInt() const
{
	return get<int>();
}

unsigned INumeric::asUInt() const
{
	return get<unsigned>();
}

long long INumeric::asLong() const
{
	return get<long long>();
}

unsigned long long INumeric::asULong() const
{
	return get<unsigned long long>();
}

double INumeric::asDouble() const
{
	return value;
}

std::string INumeric::asString() const
{
	std::ostringstream o;

	o.precision(20);
	o << value;

	return o.str();
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

}; // namespace JSON
