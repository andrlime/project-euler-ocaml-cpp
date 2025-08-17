#include "lib/shared.hpp"

using Number = uint32_t;
using Bool = uint8_t;

constexpr Number NN = 32768;

template <typename T>
using Container = std::array<T, NN>;

using Bitset = Container<Bool>;

using AbundantNumbers = std::vector<Number>;

template <Number N>
constexpr const Container<Number>
get_divisors()
{
    Container<Number> divisors{};

    for (int i = 1; i <= N; i++) {
        const int starting_number = i + i;
        for (int j = starting_number; j <= N; j += i)
            divisors[j] += i;
    }

    return divisors;
}

template <Number N>
constexpr const AbundantNumbers
get_abundant_numbers(const Container<Number>& divisors)
{
    constexpr Number NUMBERS_SIZE = 8192;
    AbundantNumbers numbers;
    numbers.reserve(NUMBERS_SIZE);

    for (std::size_t number = 1; number < divisors.size(); number++) {
        const Number sum_divisors = divisors[number];
        if (sum_divisors > number && sum_divisors <= N)
            numbers.push_back(number);
    }

    return numbers;
}

template <Number N>
constexpr const uint32_t
solve(const Number number)
{
    const Container<Number> divisors = get_divisors<N>();

    const AbundantNumbers abundants = get_abundant_numbers<N>(divisors);
    const std::size_t A = abundants.size();

    Bitset seen{};

    for (std::size_t i = 0; i < A; i++) {
        const Number first = abundants[i];
        for (std::size_t j = i; j < A; j++) {
            const Number second = abundants[j];

            if (first + second > N)
                break;

            seen[first + second] = true;
        }
    }

    uint32_t sum = 0;
    for (std::size_t i = 1; i < N; i++) {
        if (!seen[i])
            sum += i;
    }

    return sum;
}

int
main()
{
    constexpr Number input = 28123;
    solver(solve<input>, input);
    return 0;
}
