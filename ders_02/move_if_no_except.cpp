#include <iostream>
#include <utility>

struct Nec
{
    Nec() {}

    Nec(const Nec&) // may throw exception
    {
        std::cout << "Nec copy ctor\n";
    }

    Nec(Nec&&) // may throw exception
    {
        std::cout << "Nec move ctor\n";
    }
};

struct Erg
{
    Erg() {}

    Erg(const Erg&) noexcept
    {
        std::cout << "Erg copy ctor\n";
    }

    Erg(Erg&&) noexcept
    {
        std::cout << "Erg move ctor\n";
    }
};

int main()
{
    Nec mynec;
    Erg myerg;

    auto nec = std::move_if_noexcept(mynec);
    auto erg = std::move_if_noexcept(myerg);
}
