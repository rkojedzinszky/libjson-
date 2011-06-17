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

};

#endif
