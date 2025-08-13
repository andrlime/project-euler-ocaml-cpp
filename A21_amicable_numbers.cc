#include "lib/shared.hpp"

using Number = int32_t;
using DivisorsContainer = std::array<Number, 16384>;

constexpr const bool
is_amicable(const Number number, const Number max, const DivisorsContainer& divisors)
{
    Number sum_divisors = divisors[number];
    if (number == sum_divisors)
        return false;
    if (!sum_divisors)
        return false;
    if (sum_divisors > max)
        return false;
    Number sum_divisors_of_sum_divisors = divisors[sum_divisors];
    return number == sum_divisors_of_sum_divisors;
}

constexpr const uint32_t
solve(const Number number)
{
    DivisorsContainer divisors{};

    for (int i = 1; i <= number; i++) {
        const int starting_number = i + i;
        for (int j = starting_number; j <= number; j += i)
            divisors[j] += i;
    }

    int sum = 0;
    for (int i = 1; i <= number; i++)
        if (is_amicable(i, number, divisors))
            sum += i;

    return sum;
}

int
main()
{
    constexpr Number input = 10000;
    solver(solve, input);
    return 0;
}
