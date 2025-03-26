#include <iostream>

template <typename T>
struct ValCat {
	static constexpr const char* p = "PRVALUE";
};

template <typename T>
struct ValCat<T&> {
	static constexpr const char* p = "LVALUE";
};


template <typename T>
struct ValCat<T&&> {
	static constexpr const char* p = "XVALUE";
};

#define pvc(expr)  std::cout << "value category of expr "  #expr  << \
" is " << ValCat<decltype((expr))>::p << '\n';


struct Nec {
	int f(int);
};

enum Color { White, Yellow, Red, Brown, Blue, Black };


Nec foo();

int main()
{
	Nec nec;

	int x = 4;

	pvc(1);  //PRValue
	pvc(true);  //PRValue
	pvc(false); //PRValue
	pvc(nullptr); //PRValue
	pvc(Nec{}); //PRValue
	pvc(x + 1); //PRValue
	pvc(x++);  //PRValue
	pvc(x > 2);  //PRValue
	pvc(x--);  //PRValue
	pvc(&x);  //PRValue
	pvc(foo());  //PRValue
	pvc(Blue);  //PRValue
}
