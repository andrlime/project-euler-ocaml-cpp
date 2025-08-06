#include "lib/shared.hpp"

constexpr uint32_t strlength = 50;
constexpr uint32_t firstN = 10;

const std::string
solve(const std::vector<std::string>& numbers)
{
    uint32_t carry = 0;
    std::string sum_reversed = "";
    for (int i = strlength - 1; i >= 0; i--) {
        uint32_t sum = carry;
        for (std::string n : numbers) {
            sum += static_cast<uint32_t>(n[i] - '0');
        }

        sum_reversed += static_cast<char>(sum % 10 + '0');
        carry = sum / 10;
    }

    while (carry) {
        sum_reversed += static_cast<char>(carry % 10 + '0');
        carry /= 10;
    }

    std::string result = "";
    for (int i = 1; i <= firstN; i++) {
        const uint32_t revlen = sum_reversed.length();
        result.push_back(sum_reversed[revlen - i]);
    }
    return result;
}

int
main()
{
    std::vector<std::string> input;
    std::ifstream file("input_0013.txt");

    std::string line;
    while (std::getline(file, line)) {
        input.push_back(line);
    }

    solver(solve, input);

    file.close();
    return 0;
}
