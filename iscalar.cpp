#include <iscalar.hpp>

namespace JSON
{

bool IScalar::isNull() const throw ()
{
	return false;
}

IScalar::operator bool() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

IScalar::operator int() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

IScalar::operator std::string() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &IScalar::operator[](int idx) throw (std::bad_cast)
{
	throw std::bad_cast();
}

Value &IScalar::operator[](const std::string &f) throw (std::bad_cast)
{
	throw std::bad_cast();
}

size_t IScalar::size() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

}; // namespace JSON
