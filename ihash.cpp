#include <ihash.hpp>
#include <util.hpp>

namespace JSON
{

Value &IHash::operator[](const std::string &f) throw ()
{
	return hash[f];
}

void IHash::toStream(std::ostream &o) const
{
	o << "{";

	for (std::map<std::string, Value>::const_iterator I = hash.begin(); I != hash.end(); I++) {
		if (I != hash.begin()) {
			o << ",";
		}

		stringtojsonstream(I->first, o);
		o << ":";
		(I->second).toStream(o);
	}

	o << "}";
}

size_t IHash::size() const throw ()
{
	return hash.size();
}

}; // namespace JSON
