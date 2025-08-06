#include "lib/big_number.hpp"
#include "lib/shared.hpp"

const uint32_t
solve(int32_t number)
{
    lib::big_number<512> bn;

    for (int i = 1; i < number; i++)
        bn.multiply(i);

    return bn.sum_digits();
}

int
main()
{
    constexpr int32_t input = 100;
    solver(solve, input);
    return 0;
}
