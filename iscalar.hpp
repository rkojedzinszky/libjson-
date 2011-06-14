#ifndef JSON_ISCALAR_HPP
#define JSON_ISCALAR_HPP

#include <ivalue.hpp>

namespace JSON
{

class IScalar : public IValue
{
public:
	// scalars
	bool isNull() const throw ();

	// boolean
	virtual operator bool() const throw (std::bad_cast);

	// int
	virtual operator int() const throw (std::bad_cast);

	// string
	virtual operator std::string() const throw (std::bad_cast);

	// array
	Value &operator[](int idx) throw (std::bad_cast);

	// hash
	Value &operator[](const std::string &f) throw (std::bad_cast);

	// common to array & hash
	size_t size() const throw (std::bad_cast);

	// clone
	virtual IScalar *clone() const = 0;
};

}; // namespace JSON

#endif
