#pragma once

#include "shared.hpp"

namespace lib {

template <uint32_t capacity>
class big_number {
private:
    std::array<uint32_t, capacity> digits;

public:
    big_number()
    {
        digits.fill(0);
        set_one();
    }

    inline void
    set_one()
    {
        digits[capacity - 1] = 1;
    }

    void
    multiply(const uint32_t by)
    {
        uint32_t carry = 0;
        for (size_t i = capacity - 1; i > 0; i--) {
            digits[i] *= by;
            digits[i] += carry;
            carry = 0;
            if (digits[i] >= 10) {
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
    }

    void
    add(const uint32_t target)
    {
        throw std::runtime_error("unimplemented");
    }

    inline uint32_t
    sum_digits()
    {
        return std::accumulate(digits.begin(), digits.end(), 0);
    }
};

} // namespace lib
