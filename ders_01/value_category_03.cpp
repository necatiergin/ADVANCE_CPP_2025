//Telegram grubumuzda sorulan bir sorunun cevabı olarak

#include <type_traits>
#include <iostream>

template<typename T>
void print_val_cat()
{
	if constexpr (std::is_lvalue_reference_v<T>)
		std::cout << "L value\n";
	else if constexpr (std::is_rvalue_reference_v<T>)
		std::cout << "X value\n";
	else if (!std::is_reference_v<T>)
		std::cout << "PR value\n";
}

#define  expr(e)      decltype((e))

int&& foo() { return 1; }

int main()
{
	int x{};

	print_val_cat<expr(x)>();
	print_val_cat<expr(x + 5)>();
	print_val_cat<expr(foo())>();
}
