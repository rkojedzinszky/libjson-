#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/intrusive_ptr.hpp>

namespace JSON
{

class ValueBase;

void intrusive_ptr_add_ref(ValueBase *v);
void intrusive_ptr_release(ValueBase *v);

class IScalar ;
class IArray ;

class Value
{
private:
	typedef boost::intrusive_ptr<ValueBase> valueType;
	valueType value;

protected:
	Value(IArray *a);

public:
	Value();
	Value(const Value &v);
	Value &operator=(const Value &v);

	// scalar
	Value(const std::string &s);
	Value &operator=(const std::string &s);
	const std::string &str() const throw (std::exception);
	bool isNull() const throw (std::bad_cast);

	// array
	Value &operator[](int idx) throw (std::bad_cast);

	// hash
	Value &operator[](const std::string &f) throw (std::bad_cast);

	// common to array & hash
	size_t size() const throw (std::bad_cast);

	friend Value Array();
};

Value Array();
};

#endif
