#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <typeinfo>

namespace JSON
{

class Value;

class IValue
{
public:
	int refcnt;
	IValue() : refcnt(0) { };
	virtual ~IValue();

	// scalar
	virtual const std::string &str() const throw (std::exception);
	virtual bool isNull() const throw (std::bad_cast);

	// array
	virtual Value &operator[](int idx) throw (std::bad_cast);

	// hash
	virtual Value &operator[](const std::string &f) throw (std::bad_cast);

	// common to array & hash
	virtual size_t size() const throw (std::bad_cast);
};

}; // namespace JSON

#endif
