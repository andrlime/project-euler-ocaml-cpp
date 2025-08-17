#include "lib/shared.hpp"

using Char = char;
using Bool = bool;
using Number = uint64_t;

template <typename T>
using Container = std::array<T, 10>;
using String = std::string;

using Characters = Container<Char>;
using Visited = Container<Bool>;

constexpr Characters charset = {
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
};

constexpr Number N = 10;

void
dfs(String& current, Visited& visited, Number& count, const Number max, String& answer)
{
    if (current.length() == N) {
        count++;
        if (count == max)
            answer = current;
        return;
    }

    for (std::size_t i = 0; i < N; i++) {
        if (visited[i])
            continue;

        current.push_back(charset[i]);
        visited[i] = true;
        dfs(current, visited, count, max, answer);
        visited[i] = false;
        current.pop_back();
    }

    return;
}

const String
solve(const Number n)
{
    Visited visited{};
    Number count = 0;

    String current;
    String answer;

    dfs(current, visited, count, n, answer);

    return answer;
}

int
main()
{
    constexpr Number input = 1000000;
    solver(solve, input);
    return 0;
}
