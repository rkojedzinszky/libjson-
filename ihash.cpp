#include <ihash.hpp>

namespace JSON
{

Value &IHash::operator[](const std::string &f) throw ()
{
	return hash[f];
}

size_t IHash::size() const throw ()
{
	return hash.size();
}

}; // namespace JSON
