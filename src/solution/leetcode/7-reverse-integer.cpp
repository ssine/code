#include "leetcode.h"

template <typename T>
int get_integer_num_digits(T n) {
  int cnt = 0;
  while (n != 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

class Solution {
 public:
  int reverse(int x) {
    uint64_t ans = 0;
    bool negative = false;
    if (x < 0) {
      if (x == numeric_limits<int>::min()) return 0;
      negative = true;
      x = -x;
    }
    int num_digits = get_integer_num_digits(x);
    uint64_t level = 1;
    while (x) {
      uint64_t base = pow(10, num_digits - 1);
      ans += x / base * level;
      x %= base;
      num_digits--;
      level *= 10;
    }
    int res = ans > numeric_limits<int>::max() ? 0 : ans;
    if (negative) {
      res = - res;
    }
    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.reverse(0) << endl;
  cout << sol.reverse(-0) << endl;
  cout << sol.reverse(1) << endl;
  cout << sol.reverse(-1) << endl;
  cout << sol.reverse(123) << endl;
  cout << sol.reverse(-123) << endl;
  cout << sol.reverse(120) << endl;
  cout << sol.reverse(numeric_limits<int>::max()) << endl;
  cout << sol.reverse(numeric_limits<int>::min() + 1) << endl;
  return 0;
}
