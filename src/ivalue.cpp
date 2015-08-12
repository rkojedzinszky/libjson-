#include <sstream>
#include <typeinfo>

#include <json/value.hpp>
#include <json/util.hpp>

namespace JSON
{

IValue::Type IValue::type() const
{
	return JSON_NULL;
}

IValue* IValue::clone() const
{
	return new IValue();
}

bool IValue::getBool() const
{
	throw bad_cast();
}

int IValue::getInt() const
{
	throw bad_cast();
}

unsigned IValue::getUInt() const
{
	throw bad_cast();
}

long long IValue::getLong() const
{
	throw bad_cast();
}

unsigned long long IValue::getULong() const
{
	throw bad_cast();
}

double IValue::getDouble() const
{
	throw bad_cast();
}

const std::string& IValue::getString() const
{
	throw bad_cast();
}

bool IValue::asBool() const
{
	throw bad_cast();
}

int IValue::asInt() const
{
	throw bad_cast();
}

unsigned IValue::asUInt() const
{
	throw bad_cast();
}

long long IValue::asLong() const
{
	throw bad_cast();
}

unsigned long long IValue::asULong() const
{
	throw bad_cast();
}

double IValue::asDouble() const
{
	throw bad_cast();
}

std::string IValue::asString() const
{
	throw bad_cast();
}

IValue::Array& IValue::array()
{
	throw bad_cast();
}

const IValue::Array& IValue::array() const
{
	throw bad_cast();
}

IValue::Object& IValue::object()
{
	throw bad_cast();
}

const IValue::Object& IValue::object() const
{
	throw bad_cast();
}

size_t IValue::size() const
{
	throw bad_cast();
}

bool IValue::operator==(const IValue& /* r */) const
{
	throw bad_cast();
}

bool IValue::operator<(const IValue& /* r */) const
{
	throw bad_cast();
}

bool IValue::operator<=(const IValue& /* r */) const
{
	throw bad_cast();
}

void IValue::toStream(std::ostream& o) const
{
	o << "null";
}

void IValue::fromStream(std::istream& i)
{
	if (sget(i) != 'n' || sget(i) != 'u' || sget(i) != 'l' || sget(i) != 'l') {
		throw ParserError("expecting null");
	}
}

}; // namespace JSON
