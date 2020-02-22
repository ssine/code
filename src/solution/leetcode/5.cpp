#include "leetcode.h"

class Solution {
 public:
  string longestPalindrome(string s) {
    size_t max_len = 0, max_l = 0, max_r = 0;

    auto test_and_update = [&s, &max_len, &max_l, &max_r] (int l, int r) {
      size_t len = 0;
      while (l >= 0 && r < s.size()) {
        if (s[l] == s[r]) {
          l == r ? len ++ : len += 2;
          if (len > max_len) {
            max_len = len;
            max_l = l;
            max_r = r + 1;
          }
          l--; r++;
        } else {
          return;
        }
      }
    };

    for (int mid = 0; mid < s.size(); mid ++) {
      test_and_update(mid, mid);
      if (mid + 1 < s.size()) test_and_update(mid, mid + 1);
    }

    return s.substr(max_l, max_r - max_l);
  }
};

int main() {
  Solution sol;
  cout << sol.longestPalindrome("") << endl;
  cout << sol.longestPalindrome("a") << endl;
  cout << sol.longestPalindrome("babad") << endl;
  cout << sol.longestPalindrome("cbbd") << endl;
  cout << sol.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
  return 0;
}
