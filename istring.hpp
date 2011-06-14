#ifndef JSON_ISTRING_HPP
#define JSON_ISTRING_HPP

#include <iscalar.hpp>

namespace JSON
{

class IString : public IScalar
{
private:
	std::string value;

public:
	IString(const std::string &s = "");
	operator std::string () const throw ();

	IScalar *clone() const;
};

}; // namespace JSON

#endif
