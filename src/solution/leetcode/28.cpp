#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int strStr(string haystack, string needle) {
    auto pos = haystack.find(needle);
    if (pos == string::npos) return -1;
    else return pos;
  }
};

int main() {
  Solution sol;
  cout << sol.strStr("hello", "ll") << endl;
  cout << sol.strStr("aaaaa", "bba") << endl;
  cout << sol.strStr("aaaaa", "") << endl;
  return 0;
}
