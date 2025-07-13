#include <cassert>
#include <chrono>
#include <cmath>

#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numbers>
#include <numeric>
#include <ranges>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

template <typename Func, typename Input>
void
solver(Func func, const Input& input)
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    int result = func(input);
    auto end = high_resolution_clock::now();

    std::cout << "Solution: " << result << '\n';
    auto duration_ms = duration<double, std::milli>(end - start).count();
    std::cout << "Time: " << duration_ms << " ms\n";
}

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
