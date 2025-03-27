#include <iostream>

class Myclass {
public:
	Myclass() = default;

	Myclass& operator=(const Myclass&)
	{
		//...
		std::cout << "copy assignment\n";
		return *this;
	}

	Myclass& operator=(Myclass &&)
	{
		//...
		std::cout << "move assignment\n";
		return *this;
	}

	Myclass(const Myclass&) = default;
	Myclass(Myclass&&) = default;
};

Myclass foo()
{
	Myclass ret;

	return ret;
}

const Myclass bar()
{
	Myclass ret;

	return ret;
}

int main()
{
	Myclass x;

	x = foo(); //copy assignment
	x = bar(); //move assignment
}
