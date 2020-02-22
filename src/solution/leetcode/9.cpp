#include "leetcode.h"

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;
    int temp = x, reversed = 0;
    while (temp > reversed) {
      reversed = temp % 10 + reversed * 10;
      temp /= 10;
    }
    return (temp == reversed) || (temp == reversed / 10);
  }
};

int main() {
  Solution sol;
  cout << sol.isPalindrome(121) << endl;
  cout << sol.isPalindrome(-121) << endl;
  cout << sol.isPalindrome(10) << endl;
  return 0;
}
