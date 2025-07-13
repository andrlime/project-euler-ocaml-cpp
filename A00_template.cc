#include "shared.hpp"

const std::size_t solve (const int n) {
  std::size_t ct = 0;
  for (std::size_t i = 0; i <= n; i ++) {
    ct += i;
    ct %= 1000000007;
  }
  return ct;
}

int main() {
  constexpr int input = 10000000;
  solver(solve, input);
  return 0;
}
