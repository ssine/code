#include "leetcode.h"

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    set<uint64_t> uglyNumbers;
    uglyNumbers.insert(1);
    bool stopNew = false;
    uint64_t m = 0;
    for (int i = 1; i < n; i++) {
      uint64_t cur = *uglyNumbers.begin();
      for (int p : primes) {
        if (stopNew && p * cur > m)
          break;
        uglyNumbers.insert(p * cur);
      }
      uglyNumbers.erase(uglyNumbers.begin());
      if (!stopNew) {
        if (i + uglyNumbers.size() > n) {
          stopNew = true;
          m = *uglyNumbers.rbegin();
        }
      }
    }
    return *uglyNumbers.begin();
  }
};

int main() {
  Solution sol;
  // 859963392
  // vector<int> arr = {2, 3, 5};
  // cout << sol.nthSuperUglyNumber(1500, arr) << endl;
  // 1092889481
  vector<int> arr = {7,   19,  29,  37,  41,  47,  53,  59,  61,  79,  83,  89,  101, 103, 109,
                     127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251};
  cout << sol.nthSuperUglyNumber(100000, arr) << endl;
  return 0;
}
