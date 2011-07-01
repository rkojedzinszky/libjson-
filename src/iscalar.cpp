#include <typeinfo>

#include <json/iscalar.hpp>

namespace JSON
{

bool IScalar::isNull() const
{
	return false;
}

size_t IScalar::size() const
{
	throw std::bad_cast();
}

}; // namespace JSON
