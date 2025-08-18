#pragma once

#include "shared.hpp"

namespace lib {
using Short = int16_t;
using UShort = uint16_t;

using Number = int32_t;
using UNumber = uint32_t;

using Long = int64_t;
using ULong = uint64_t;

using Bool = bool;
using Bool64 = uint64_t;

using Char = char;
using String = std::string;

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <typename T>
concept Unsigned = std::is_integral_v<T> && std::is_unsigned_v<T>;
} // namespace lib
