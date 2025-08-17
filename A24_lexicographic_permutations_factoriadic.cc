#include "lib/shared.hpp"

using Number = int64_t;
using Bool = bool;
using Char = char;
using String = std::string;

template <typename T>
using Container = std::array<T, 16>;
using Visited = Container<Bool>;

constexpr Container<Char> charset = {
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
};

constexpr Number N = 10;

constexpr const Container<Number>
get_factorials()
{
    Container<Number> factorials{};
    factorials[0] = 1;
    for (int i = 1; i < N; i++)
        factorials[i] = factorials[i - 1] * i;
    return factorials;
}

const Char
get_next_char(Number index, Visited& v)
{
    Number count = 0;
    for (std::size_t i = 0; i < N; i++) {
        Bool& visited = v[i];
        const Char character = charset[i];

        if (visited)
            continue;

        if (count == index) {
            visited = true;
            return character;
        }

        count++;
    }

    throw std::runtime_error("out of characters to permute");
}

const String
solve(Number n)
{
    n -= 1;

    constexpr const auto factorials = get_factorials();
    String soln;
    Visited visited{};

    for (Number place = (N - 1); place >= 0; place--) {
        const Number base = factorials[place];
        const Number index = n / base;

        soln.push_back(get_next_char(index, visited));
        n %= base;
    }

    return soln;
}

int
main()
{
    constexpr Number input = 1000000;
    solver(solve, input);
    return 0;
}
