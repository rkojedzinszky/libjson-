#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/intrusive_ptr.hpp>

namespace JSON
{

class IValue;

void intrusive_ptr_add_ref(IValue *v);
void intrusive_ptr_release(IValue *v);

class IScalar ;
class IArray ;
class IHash ;

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
	friend Value Hash();
};

Value Array();
Value Hash();

}; // namespace JSON

#endif
