#include "lib/shared.hpp"

const int64_t
solve(const std::vector<std::vector<int>>& triangle)
{
    const size_t N = triangle.size();
    std::array<int64_t, 128> dp{};

    dp.fill(INT_MIN);
    dp[0] = triangle[0][0];

    for (std::size_t i = 1; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (j > 0) [[likely]]
                dp[j] = std::max(dp[j], dp[j - 1]);
            dp[j] += triangle[i][j];
        }
    }

    return std::ranges::max(dp);
}

int
main()
{
    std::vector<std::vector<int>> input;
    std::ifstream file("input_0067.txt");

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, ' ');

        std::vector<int> numbers;
        for (std::string s : tokens) {
            numbers.push_back(stoi(s));
        }

        input.push_back(numbers);
    }

    solver(solve, input);

    file.close();
    return 0;
}
