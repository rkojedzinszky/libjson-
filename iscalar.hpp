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

	// common to array & hash
	size_t size() const throw (std::bad_cast);

	// serialization
	virtual void toStream(std::ostream &o) const = 0;

	// clone
	virtual IScalar *clone() const = 0;
};

}; // namespace JSON

#endif
