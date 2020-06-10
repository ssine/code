#include "leetcode.h"
#include "utils.h"

class Solution {
  vector<int> digits;
  vector<int> nums;

public:
  int countAll(int pos) {
    if (pos == 0) {
      return 1;
    }
    return pow(10, pos) + 10 * countAll(pos - 1);
  }

  int count(int pos) {
    int d = digits[pos];
    if (pos == 0) {
      return d >= 1 ? 1 : 0;
    }
    if (d > 1) {
      return d * countAll(pos - 1) + pow(10, pos) + count(pos - 1);
    } else if (d < 1) {
      return count(pos - 1);
    } else {
      return countAll(pos - 1) + nums[pos - 1] + 1 + count(pos - 1);
    }
  }

  int countDigitOne(int n) {
    if (n <= 0) return 0;
    digits.clear();
    nums.clear();
    int t = n;
    while (t) {
      digits.push_back(t % 10);
      t /= 10;
    }
    t = 1;
    nums.push_back(digits[0]);
    for (int i = 1; i < digits.size(); i++) {
      t *= 10;
      nums.push_back(nums[i - 1] + digits[i] * t);
    }
    return count(digits.size() - 1);
  }
};

int main() {
  Solution sol;
  cout << sol.countDigitOne(0) << endl;
  cout << sol.countDigitOne(1) << endl;
  cout << sol.countDigitOne(2) << endl;
  cout << sol.countDigitOne(3) << endl;
  cout << sol.countDigitOne(4) << endl;
  cout << sol.countDigitOne(5) << endl;
  cout << sol.countDigitOne(6) << endl;
  cout << sol.countDigitOne(7) << endl;
  cout << sol.countDigitOne(8) << endl;
  cout << sol.countDigitOne(9) << endl;
  cout << sol.countDigitOne(10) << endl;
  cout << sol.countDigitOne(11) << endl;
  cout << sol.countDigitOne(12) << endl;
  cout << sol.countDigitOne(13) << endl;
  cout << sol.countDigitOne(14) << endl;
  cout << sol.countDigitOne(15) << endl;
  cout << sol.countDigitOne(16) << endl;
  cout << sol.countDigitOne(17) << endl;
  cout << sol.countDigitOne(18) << endl;
  cout << sol.countDigitOne(19) << endl;
  cout << sol.countDigitOne(20) << endl;
  cout << sol.countDigitOne(21) << endl;
  cout << sol.countDigitOne(1410065408) << endl;
  return 0;
}
