#pragma once

#include "shared.hpp"
#include "types.hpp"

namespace lib {

template <Unsigned T, UNumber capacity>
class big_number {
public:
    std::array<T, capacity> digits;

    big_number() { set_one(); }

    inline void
    set_n(T n)
    {
        set_one();
        multiply(n);
    }

    inline void
    set_one()
    {
        digits.fill(0);
        digits[capacity - 1] = 1;
    }

    void
    multiply(const UNumber by)
    {
        T carry = 0;
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
    add(const UNumber with)
    {
        UNumber amount = with;
        UNumber carry = 0;
        for (size_t i = capacity - 1; i > 0; i--) {
            if (amount == 0 && carry == 0)
                break;
            digits[i] += (amount % 10) + carry;
            amount /= 10;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
    }

    inline T
    sum_digits()
    {
        return std::accumulate(digits.begin(), digits.end(), 0);
    }
};

} // namespace lib
