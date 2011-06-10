#include "base.hpp"

void intrusive_ptr_add_ref(ValueBase *v)
{
	++v->refcnt;
}

void intrusive_ptr_release(ValueBase *v)
{
	if (--v->refcnt == 0)
		delete v;
}

ValueBase::~ValueBase()
{
}

const std::string &ValueBase::str() const throw (std::runtime_error)
{
	throw std::bad_cast();
}

bool ValueBase::isNull() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &ValueBase::operator[](int idx) throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &ValueBase::operator[](const std::string &f) throw (std::bad_cast)
{
	throw std::bad_cast();
}

