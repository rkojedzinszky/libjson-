#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/intrusive_ptr.hpp>
#include <ostream>

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
	operator const std::string&() const throw (std::bad_cast);

	// array
	Value &operator[](int idx) throw (std::bad_cast);

	// hash
	Value &operator[](const std::string &f) throw (std::bad_cast);
	Value &operator[](const char *f) throw (std::bad_cast);

	// common to array & hash
	size_t size() const throw (std::bad_cast);

	// operators
	bool operator==(const Value &r) const throw (std::bad_cast);
	bool operator!=(const Value &r) const throw (std::bad_cast) {
		return !operator==(r);
	}
	bool operator<(const Value &r) const throw (std::bad_cast);
	bool operator>(const Value &r) const throw (std::bad_cast) {
		return r.operator<(*this);
	}
	bool operator<=(const Value &r) const throw (std::bad_cast);
	bool operator>=(const Value &r) const throw (std::bad_cast) {
		return r.operator<=(*this);
	}

	friend Value Array();
	friend Value Hash();

	// serialization
	void toStream(std::ostream &o) const;
};

Value Array();
Value Hash();

}; // namespace JSON

static inline std::ostream &operator<<(std::ostream &o, JSON::Value &v)
{
	v.toStream(o);
	return o;
}

#endif
