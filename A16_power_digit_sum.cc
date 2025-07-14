#include "shared.hpp"

constexpr uint32_t number_size = 512;
typedef std::array<uint32_t, number_size> big_number_t;

void
multiply(big_number_t& bn, const uint32_t by)
{
    uint32_t carry = 0;
    for (size_t i = number_size - 1; i > 0; i--) {
        bn[i] *= by;
        bn[i] += carry;
        carry = 0;
        if (bn[i] >= 10) {
            carry = bn[i] / 10;
            bn[i] %= 10;
        }
    }
}

const uint32_t
solve(int32_t exponent)
{
    big_number_t big_number;
    big_number.fill(0);
    big_number[number_size - 1] = 1;

    while (exponent > 0) {
        multiply(big_number, 2);
        exponent--;
    }

    uint32_t total = 0;
    for (int i : big_number) {
        total += i;
    }
    return total;
}

int
main()
{
    constexpr int32_t input = 1000;
    solver(solve, input);
    return 0;
}
