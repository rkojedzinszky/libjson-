#ifndef JSON_REFCOUNTED_HPP
#define JSON_REFCOUNTED_HPP

namespace JSON
{

class refcounted {
protected:
	int refcnt;
	refcounted();
public:
	virtual ~refcounted();

	friend void intrusive_ptr_add_ref(refcounted *v);
	friend void intrusive_ptr_release(refcounted *v);
};

template <typename T>
class refcounted_ptr {
public:
	refcounted_ptr();
	refcounted_ptr(T *p);
	refcounted_ptr(const refcounted_ptr<T> &p);
	refcounted_ptr &operator=(T *p);
	refcounted_ptr &operator=(const refcounted_ptr<T> &p);
	~refcounted_ptr();

	T *operator->() const;
	T &operator*() const;

private:
	T *p_;
};

inline refcounted::refcounted() : refcnt(0)
{
}

inline refcounted::~refcounted()
{
}

inline void intrusive_ptr_add_ref(refcounted *v)
{
	++v->refcnt;
}

inline void intrusive_ptr_release(refcounted *v)
{
	if (--v->refcnt == 0) {
		delete v;
	}
}

template <typename T>
refcounted_ptr<T>::refcounted_ptr() : p_(0)
{
}

template <typename T>
refcounted_ptr<T>::refcounted_ptr(T *p) : p_(p)
{
	if (p_ != 0) {
		intrusive_ptr_add_ref(p_);
	}
}

template <typename T>
refcounted_ptr<T>::refcounted_ptr(const refcounted_ptr<T> &p) : p_(p.p_)
{
	if (p_ != 0) {
		intrusive_ptr_add_ref(p_);
	}
}

template <typename T>
refcounted_ptr<T> &refcounted_ptr<T>::operator=(T *p)
{
	if (p_ != p) {
		if (p_ != 0) {
			intrusive_ptr_release(p_);
		}
		p_ = p;
		if (p_ != 0) {
			intrusive_ptr_add_ref(p_);
		}
	}

	return *this;
}

template <typename T>
refcounted_ptr<T> &refcounted_ptr<T>::operator=(const refcounted_ptr<T> &p)
{
	return operator=(p.p_);
}

template <typename T>
refcounted_ptr<T>::~refcounted_ptr()
{
	if (p_ != 0) {
		intrusive_ptr_release(p_);
	}
}

template <typename T>
T *refcounted_ptr<T>::operator->() const
{
	return p_;
}

template <typename T>
T &refcounted_ptr<T>::operator*() const
{
	return *p_;
}


};

#endif
