#include <type_traits>

template <typename T>
constexpr std::remove_reference_t<T>&& Move(T&& t)noexcept
{
	return static_cast<std::remove_reference_t<T>&&>(t);
}
