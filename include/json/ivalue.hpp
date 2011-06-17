#ifndef JSON_IVALUE_HPP
#define JSON_IVALUE_HPP

#include <string>
#include <typeinfo>
#include <ostream>

namespace JSON
{

class Value;

class IValue
{
public:
	int refcnt;
	IValue() : refcnt(0) { };
	virtual ~IValue();

	// scalars
	virtual bool isNull() const;

	// boolean
	virtual bool getBool() const;

	// numeric
	virtual double getDouble() const;

	// string
	virtual const std::string &getString() const;

	// array
	virtual Value &operator[](int idx);
	virtual Value &front();
	virtual Value &back();
	virtual void push_front(const Value &v);
	virtual void push_back(const Value &v);
	virtual Value pop_front();
	virtual Value pop_back();

	// object
	virtual Value &operator[](const std::string &f);

	// common to array & object
	virtual size_t size() const;

	// operators
	virtual bool operator==(const IValue &r) const;
	virtual bool operator<(const IValue &r) const;
	virtual bool operator<=(const IValue &r) const;

	// serialization
	virtual void toStream(std::ostream &o) const;
	virtual void fromStream(std::istream &i);
};

static inline void intrusive_ptr_add_ref(IValue *v)
{
	++v->refcnt;
}

static inline void intrusive_ptr_release(IValue *v)
{
	if (--v->refcnt == 0) {
		delete v;
	}
}

}; // namespace JSON

#endif
