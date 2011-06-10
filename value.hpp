#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/intrusive_ptr.hpp>

class ValueBase;

void intrusive_ptr_add_ref(ValueBase *v);
void intrusive_ptr_release(ValueBase *v);

class Scalar ;
class Array ;

class Value {
	private:
		typedef boost::intrusive_ptr<ValueBase> valueType;
		valueType value;

	public:
		Value();
		Value(const Value &v);
		Value(const std::string &s);
		Value &operator=(const Value &v);
		Value &operator=(const std::string &s);

		// scalar
		const std::string &str() const throw (std::runtime_error);
		bool isNull() const throw (std::bad_cast);

		// array
		Value &operator[](int idx) throw (std::bad_cast);

		// hash
		Value &operator[](const std::string &f) throw (std::bad_cast);
};

#endif
