#include "lib/shared.hpp"

inline uint64_t
next(uint64_t cur)
{
    if (cur % 2 == 1)
        return 3 * cur + 1;
    return cur / 2;
}

const int32_t
solve(const int32_t max)
{
    std::unordered_map<int32_t, std::size_t> memo;
    memo[1] = 1;

    uint64_t max_value = 0;
    int32_t max_count = 0;

    for (int i = 1; i <= 1000000; i++) {
        uint64_t cur = i;
        int32_t ct = 0;

        while (!memo.count(cur)) {
            cur = next(cur);
            ct += 1;
        }

        ct += memo[cur];
        memo[i] = ct;

        if (ct > max_count) {
            max_count = ct;
            max_value = i;
        }
    }

    return max_value;
}

int
main()
{
    constexpr int32_t input = 1000000;
    solver(solve, input);
    return 0;
}
