#include <type_traits>

template <typename T>
struct RemoveReference {
	using type = T;
};

template <typename T>
struct RemoveReference<T&> {
	using type = T;
};

template <typename T>
struct RemoveReference<T&&> {
	using type = T;
};

template <typename T>
using RemoveReference_t = typename RemoveReference<T>::type;

int main()
{
	RemoveReference_t<int&> x{ 5 };	 //int x
	RemoveReference_t<int&&> y{ x };  // int y
	RemoveReference_t<int&&> &r1 { x };  // int& r1 
	RemoveReference_t<int&&> &&r2 {0 };  // int&& r2 
}
