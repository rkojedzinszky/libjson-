#include <typeinfo>

#include <json/iscalar.hpp>

namespace JSON
{

bool IScalar::isNull() const
{
	return false;
}

}; // namespace JSON
