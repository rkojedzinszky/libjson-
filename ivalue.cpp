#include <ivalue.hpp>

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

const std::string &IValue::str() const throw (std::exception)
{
	throw std::bad_cast();
}

bool IValue::isNull() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &IValue::operator[](int idx) throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &IValue::operator[](const std::string &f) throw (std::bad_cast)
{
	throw std::bad_cast();
}

size_t IValue::size() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

}; // namespace JSON
