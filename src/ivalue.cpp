#include <json/ivalue.hpp>

namespace JSON
{

void intrusive_ptr_add_ref(IValue *v)
{
	++v->refcnt;
}

void intrusive_ptr_release(IValue *v)
{
	if (--v->refcnt == 0) {
		delete v;
	}
}

IValue::~IValue()
{
}

bool IValue::isNull() const
{
	return true;
}

IValue::operator bool() const
{
	return false;
}

IValue::operator double() const
{
	throw std::bad_cast();
}

IValue::operator const std::string&() const
{
	throw std::bad_cast();
}

Value &IValue::operator[](int idx)
{
	throw std::bad_cast();
}

Value &IValue::operator[](const std::string &f)
{
	throw std::bad_cast();
}

size_t IValue::size() const
{
	throw std::bad_cast();
}

bool IValue::operator==(const IValue &r) const
{
	throw std::bad_cast();
}

bool IValue::operator<(const IValue &r) const
{
	throw std::bad_cast();
}

bool IValue::operator<=(const IValue &r) const
{
	throw std::bad_cast();
}

void IValue::toStream(std::ostream &o) const
{
	o << "null";
}

void IValue::fromStream(std::istream &i)
{
	if (i.get() != 'n' || i.get() != 'u' || i.get() != 'l' || i.get() != 'l') {
		throw ParserError("expecting null");
	}
}

}; // namespace JSON
