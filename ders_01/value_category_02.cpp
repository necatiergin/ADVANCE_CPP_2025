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
