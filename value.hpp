#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/intrusive_ptr.hpp>

namespace JSON
{

class IValue ;

void intrusive_ptr_add_ref(IValue *v);
void intrusive_ptr_release(IValue *v);

class Value
{
private:
	typedef boost::intrusive_ptr<IValue> valueType;
	valueType value;

protected:
	Value(IValue *v);

public:
	Value();
	Value(const Value &v);
	Value &operator=(const Value &v);

	// scalars
	bool isNull() const throw ();

	// boolean
	Value(bool v);
	Value &operator=(bool v);
	operator bool() const throw (std::bad_cast);

	// int
	Value(int v);
	Value &operator=(int v);
	operator int() const throw (std::bad_cast);

	// string
	Value(const std::string &s);
	Value(const char *s);
	Value &operator=(const std::string &s);
	Value &operator=(const char *s);
	operator std::string() const throw (std::bad_cast);

	// array
	Value &operator[](int idx) throw (std::bad_cast);

	// hash
	Value &operator[](const std::string &f) throw (std::bad_cast);

	// common to array & hash
	size_t size() const throw (std::bad_cast);

	friend Value Array();
	friend Value Hash();
};

Value Array();
Value Hash();

}; // namespace JSON

#endif
