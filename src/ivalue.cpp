#include <sstream>
#include <typeinfo>

#include <json/value.hpp>
#include <json/util.hpp>

namespace JSON
{

bool IValue::isNull() const
{
	return true;
}

bool IValue::getBool() const
{
	throw std::bad_cast();
}

int IValue::getInt() const
{
	throw std::bad_cast();
}

unsigned IValue::getUInt() const
{
	throw std::bad_cast();
}

long long IValue::getLong() const
{
	throw std::bad_cast();
}

unsigned long long IValue::getULong() const
{
	throw std::bad_cast();
}

double IValue::getDouble() const
{
	throw std::bad_cast();
}

const std::string &IValue::getString() const
{
	throw std::bad_cast();
}

bool IValue::asBool() const
{
	throw std::bad_cast();
}

int IValue::asInt() const
{
	throw std::bad_cast();
}

unsigned IValue::asUInt() const
{
	throw std::bad_cast();
}

long long IValue::asLong() const
{
	throw std::bad_cast();
}

unsigned long long IValue::asULong() const
{
	throw std::bad_cast();
}

double IValue::asDouble() const
{
	throw std::bad_cast();
}

std::string IValue::asString() const
{
	throw std::bad_cast();
}

IValue::Array &IValue::array()
{
	throw std::bad_cast();
}

IValue::Object &IValue::object()
{
	throw std::bad_cast();
}

size_t IValue::size() const
{
	throw std::bad_cast();
}

bool IValue::operator==(const IValue & /* r */) const
{
	throw std::bad_cast();
}

bool IValue::operator<(const IValue & /* r */) const
{
	throw std::bad_cast();
}

bool IValue::operator<=(const IValue & /* r */) const
{
	throw std::bad_cast();
}

void IValue::toStream(std::ostream &o) const
{
	o << "null";
}

void IValue::fromStream(std::istream &i)
{
	if (sget(i) != 'n' || sget(i) != 'u' || sget(i) != 'l' || sget(i) != 'l') {
		throw ParserError("expecting null");
	}
}

}; // namespace JSON
