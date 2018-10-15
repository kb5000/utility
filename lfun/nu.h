//C++ attribute

template<typename T>
class nu
{
public:
	nu() = default;
	nu(T c):content(c)
	{
		enabled = true;
	}
	T& c()
	{
		enabled = true;
		return content;
	}
	const T& c() const
	{
		return content;
	}
	nu& clear()
	{
		enabled = false;
		return *this;
	}
	nu& release(T deft = T())
	{
		content = deft;
		enabled = false;
		return *this;
	}
	bool e()
	{
		return enabled;
	}
	bool e() const
	{
		return enabled;
	}
private:
	T content;
	bool enabled;
};
