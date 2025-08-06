#pragma once

#include "shared.hpp"

namespace lib {

constexpr uint32_t digit_capacity = 512;

class big_number {
private:
    using big_number_t = std::array<uint32_t, digit_capacity>;
    big_number_t digits{};

public:
    big_number()
    {
        // TODO: write an add() function instead of deafulting to 1
        digits.fill(0);
        digits[digit_capacity - 1] = 1;
    }

    void
    multiply(const uint32_t by)
    {
        uint32_t carry = 0;
        for (size_t i = digit_capacity - 1; i > 0; i--) {
            digits[i] *= by;
            digits[i] += carry;
            carry = 0;
            if (digits[i] >= 10) {
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
    }

    inline uint32_t
    sum_digits()
    {
        return std::accumulate(digits.begin(), digits.end(), 0);
    }
};

} // namespace lib
