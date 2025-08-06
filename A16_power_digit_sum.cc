#include "lib/big_number.hpp"
#include "lib/shared.hpp"

const uint32_t
solve(int32_t exponent)
{
    lib::big_number<512> bn;

    for (int i = 1; i <= exponent; i++)
        bn.multiply(2);

    return bn.sum_digits();
}

int
main()
{
    constexpr int32_t input = 1000;
    solver(solve, input);
    return 0;
}
