#include "shared.hpp"

const bool
decrypt(std::string &s, const std::vector<char>& cipher, const std::array<char, 3> key) {
    for (std::size_t index = 0; index < cipher.size(); index ++) {
        const char next_char = cipher[index] ^ (key[index % 3]);

        const bool is_lowercase = (next_char >= 'a' && next_char <= 'z');
        const bool is_uppercase = (next_char >= 'A' && next_char <= 'Z');
        const bool is_digit = (next_char >= '0' && next_char <= '9');
        const bool is_space = next_char == ' ';
        const bool is_reasonable_punctuation = next_char == ',' || next_char == '.' || next_char == ';' || next_char == ':';
        const bool is_other_punctuation = next_char == '!' || next_char == '-' || next_char == '?' || next_char == '\'' || next_char == '\"';
        const bool is_parenthesis = next_char == '(' || next_char == ')';
        const bool is_bracket = next_char == '[' || next_char == ']';
        const bool is_math = next_char == '+' || next_char == '/';

        if (is_lowercase || is_uppercase || is_digit || is_space || is_reasonable_punctuation || is_other_punctuation || is_parenthesis || is_bracket || is_math) {
            s.push_back(next_char);
            continue;
        }

        return false;
    }

    return true;
}

const int32_t
solve(const std::vector<char>& cipher)
{
    std::array<char, 3> key{'a', 'a', 'a'};
    std::string s;

    for (std::size_t i = 0; i < 26; i ++) {
        for (std::size_t j = 0; j < 26; j ++) {
            for (std::size_t k = 0; k < 26; k ++) {
                s.clear();
                if (!decrypt(s, cipher, key)) {
                    key[2] ++;
                    continue;
                }

                uint64_t sum = 0;
                for (char c : s) {
                    sum += c;
                }
                return sum;
            }

            key[1] ++;
            key[2] = 'a';
        }

        key[0] ++;
        key[1] = 'a';
        key[2] = 'a';
    }
    
    return -1;
}

int
main()
{
    std::vector<std::vector<int>> input;
    std::ifstream file("input_0059.txt");

    std::string line;
    std::getline(file, line);
    
    std::vector<std::string> tokens = split(line, ',');

    std::vector<char> cipher;
    for (std::string s : tokens) {
        cipher.push_back(static_cast<char>(stoi(s)));
    }

    solver(solve, cipher);

    file.close();
    return 0;
}
