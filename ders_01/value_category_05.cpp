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

struct Nec{
	int mx;
};

void func();
int& foo();


int main()
{
	Nec nec; 
	Nec* p{ &nec };
	int Nec::* mp = &Nec::mx;

	int x = 5;
	int& rx = x;
	int&& rr = 10;

	pvc(x);  // LValue
	pvc(rx);  // LValue
	pvc(rr);  // LValue
	pvc(++x);  // LValue
	pvc(--x);  // LValue
	pvec(static_cast<int&>(x));
	pvc(func); //LVALUE
	pvc(foo); //LVALUE
	pvc(foo()); //LVALUE
	pvc(std::move(foo)); //LVALUE
	pvc(*p); //LVALUE
	pvc(p[0]); //LVALUE
	pvc(x = 9); //LVALUE
	pvc(x += 3); //LVALUE
	pvc(x += 3); //LVALUE
	pvc(nec.mx); //LVALUE
	pvc(p->mx); //LVALUE
	pvc(nec.*mp); //LVALUE
	pvc(p->*mp); //LVALUE
}
