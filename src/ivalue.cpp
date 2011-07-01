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

long long IValue::getLong() const
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

long long IValue::asLong() const
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

void IValue::resize(size_t /* sz */)
{
	throw std::bad_cast();
}

Value &IValue::operator[](int /* idx */)
{
	throw std::bad_cast();
}

Value &IValue::at(int /* idx */)
{
	throw std::bad_cast();
}

Value &IValue::front()
{
	throw std::bad_cast();
}

Value &IValue::back()
{
	throw std::bad_cast();
}

void IValue::push_front(const Value & /* v */)
{
	throw std::bad_cast();
}

void IValue::push_back(const Value & /* v */)
{
	throw std::bad_cast();
}

Value IValue::pop_front()
{
	throw std::bad_cast();
}

Value IValue::pop_back()
{
	throw std::bad_cast();
}

IValue::Array &IValue::array()
{
	throw std::bad_cast();
}

Value &IValue::operator[](const std::string & /* f */)
{
	throw std::bad_cast();
}

Value IValue::keys() const
{
	throw std::bad_cast();
}

size_t IValue::erase(const std::string & /* f */)
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
