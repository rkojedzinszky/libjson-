#ifndef JSON_INUMERIC_HPP
#define JSON_INUMERIC_HPP

#include <sstream>
#include <stdexcept>
#include <typeinfo>

#include <json/iscalar.hpp>

namespace JSON
{

class INumeric : public IScalar
{
protected:
	template <typename F, typename T>
	static bool numbers_equal(volatile F &f, T t);

	template <typename T, typename S>
	static T get(const S s);

public:
	// return type info
	Type type() const;

	int getInt() const = 0;
	unsigned getUInt() const = 0;
	long long getLong() const = 0;
	unsigned long long getULong() const = 0;
	double getDouble() const = 0;

	// converter functions
	bool asBool() const = 0;
	int asInt() const = 0;
	unsigned asUInt() const = 0;
	long long asLong() const = 0;
	unsigned long long asULong() const = 0;
	double asDouble() const = 0;
	std::string asString() const = 0;

	bool operator==(const IValue &r) const = 0;
	bool operator<(const IValue &r) const = 0;
	bool operator<=(const IValue &r) const = 0;

	void toStream(std::ostream &o) const = 0;
	static INumeric * fromStream(std::istream &is);
};

template <typename F, typename T>
inline bool INumeric::numbers_equal(volatile F &f, T t)
{
	return static_cast<T>(f) == t;
}

template <typename T, typename S>
T INumeric::get(const S s)
{
	T r = static_cast<T>(s);

	if (!numbers_equal(r, s)) {
		std::ostringstream o;
		o.precision(20);
		o << "INumeric::get<" << typeid(T).name() << "," << typeid(S).name() << ">(): " << s << " cannot be stored without loss";
		throw std::domain_error(o.str());
	}

	return r;
}


}; // namespace JSON

#endif
