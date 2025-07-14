#include "shared.hpp"

constexpr size_t grid_size = 20;
constexpr size_t adjacent_count = 4;

enum Direction {
    Up = 0,
    Down,
    Left,
    Right,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight,
};

const int64_t
solve(const std::vector<std::vector<int>>& grid)
{
    std::array<std::array<int64_t, grid_size>, grid_size> products{};
    for (int i = 0; i < grid_size; i++)
        products[i].fill(0);

    std::array<int64_t, 8> arr{};
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            arr.fill(1);
            for (int k = 0; k < adjacent_count; k++) {
                if (j - k >= 0) [[likely]]
                    arr[Direction::Up] *= grid[i][j - k];
                else
                    arr[Direction::Up] = 0;

                if (j + k < grid_size) [[likely]]
                    arr[Direction::Down] *= grid[i][j + k];
                else
                    arr[Direction::Down] = 0;

                if (i - k >= 0) [[likely]]
                    arr[Direction::Left] *= grid[i - k][j];
                else
                    arr[Direction::Left] = 0;

                if (i + k < grid_size) [[likely]]
                    arr[Direction::Right] *= grid[i + k][j];
                else
                    arr[Direction::Right] = 0;

                if (i - k >= 0 && j - k >= 0) [[likely]]
                    arr[Direction::UpLeft] *= grid[i - k][j - k];
                else
                    arr[Direction::UpLeft] = 0;

                if (i + k < grid_size && j - k >= 0) [[likely]]
                    arr[Direction::UpRight] *= grid[i + k][j - k];
                else
                    arr[Direction::UpRight] = 0;

                if (i - k >= 0 && j + k < grid_size) [[likely]]
                    arr[Direction::DownLeft] *= grid[i - k][j + k];
                else
                    arr[Direction::DownLeft] = 0;

                if (i + k < grid_size && j + k < grid_size) [[likely]]
                    arr[Direction::DownRight] *= grid[i + k][j + k];
                else
                    arr[Direction::DownRight] = 0;
            }
            products[i][j] = std::ranges::max(arr);
        }
    }

    return std::ranges::max(products | std::views::join);
}

int
main()
{
    std::vector<std::vector<int>> input;
    std::ifstream file("input_0011.txt");

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
