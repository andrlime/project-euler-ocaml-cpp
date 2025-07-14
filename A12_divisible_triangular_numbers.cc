#include "shared.hpp"

std::unordered_map<uint64_t, size_t>
factorise(uint64_t n)
{
    std::unordered_map<uint64_t, size_t> factors;
    for (uint64_t i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }

    if (n > 1)
        factors[n]++;

    return factors;
}

const std::size_t
count_number_of_divisors(uint64_t n)
{
    const std::unordered_map<uint64_t, size_t> factors = factorise(n);
    size_t result = 1;

    for (auto& [_, exp] : factors)
        result *= (exp + 1);

    return result;
}

const std::size_t
solve(const int n)
{
    uint64_t next = 2, cur = 1;

    while (count_number_of_divisors(cur) < n)
        cur += (next++);

    return cur;
}

int
main()
{
    constexpr int input = 500;
    solver(solve, input);
    return 0;
}
