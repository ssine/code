#include "leetcode.h"

template <typename T, T N> constexpr auto make_constexpr_array(std::integral_constant<T, N>) {
  std::array<int, N> result = {};
  int cur = 1;
  result[0] = 1;
  for (int i = 1; i < N; i++) {
    cur *= 4;
    result[i] = cur;
  }
  return result;
}

class Solution {
public:
  bool isPowerOfFour(int num) {
    constexpr int N = 16; // log(numeric_limits<int>::max()) / log(4), however log is not a constexpr function
    constexpr auto arr = make_constexpr_array(std::integral_constant<int, N>{});
    for (int p : arr)
      if (p == num)
        return true;
    return false;
  }
};

int main() {
  Solution sol;
  cout << sol.isPowerOfFour(16) << endl;
  cout << sol.isPowerOfFour(5) << endl;
  cout << sol.isPowerOfFour(1) << endl;
  return 0;
}
