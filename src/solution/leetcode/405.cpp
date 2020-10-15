#include "leetcode.h"

class Solution {
public:
  string toHex(int num) {
    string s = "";
    uint32_t unum = num;
    do {
      uint32_t rem = unum % 16;
      unum = unum / 16;
      char add = rem > 9 ? 'a' + rem - 10 : '0' + rem;
      s = add + s;
    } while (unum != 0);
    return s;
  }
};

int main() {
  Solution sol;
  cout << sol.toHex(0) << endl;
  cout << sol.toHex(26) << endl;
  cout << sol.toHex(-1) << endl;
  return 0;
}
