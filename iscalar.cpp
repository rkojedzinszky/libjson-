#include <iscalar.hpp>

namespace JSON
{

bool IScalar::isNull() const throw ()
{
	return false;
}

size_t IScalar::size() const throw (std::bad_cast)
{
	throw std::bad_cast();
}

}; // namespace JSON
