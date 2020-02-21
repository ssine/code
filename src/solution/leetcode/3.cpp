#include "leetcode.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    set<char> contained;
    int l = 0, r = 0;
    int max_len = 0;
    while (r != s.length()) {
      if (contained.count(s[r]) != 1) {
        contained.insert(s[r]);
        r ++;
        max_len = max(max_len, r - l);
      } else {
        contained.erase(s[l]);
        l ++;
      }
    }
    return max_len;
  }
};

int main() {
  Solution sol;
  cout << sol.lengthOfLongestSubstring("bbbbb");
  return 0;
}
