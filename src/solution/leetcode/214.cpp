#include "leetcode.h"
#include "utils.h"

class Solution {
  vector<int> getPMT(string &s) {
    vector<int> next(s.size() + 1, 0);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < s.size()) {
      if (j == -1 || s[i] == s[j]) {
        i++;
        j++;
        next[i] = j;
      } else {
        j = next[j];
      }
    }
    return next;
  }

public:
  string shortestPalindrome(string s) {
    if (s.size() == 0)
      return "";
    size_t n = s.size();
    string rs;
    reverse_copy(s.begin(), s.end(), back_inserter(rs));
    auto next = getPMT(s);
    int i = 0, j = 0;
    while (j < n) {
      if (i == -1 || s[i] == rs[j]) {
        i++;
        j++;
      } else {
        i = next[i];
      }
    }
    string prefix;
    reverse_copy(s.begin() + (i <= 0 ? 1 : i), s.end(), back_inserter(prefix));
    return prefix + s;
  }
};

int main() {
  Solution sol;
  cout << sol.shortestPalindrome("aacecaaa") << endl;
  cout << sol.shortestPalindrome("abbacd") << endl;
  cout << sol.shortestPalindrome("abcd") << endl;
  cout << sol.shortestPalindrome("a") << endl;
  cout << sol.shortestPalindrome("ab") << endl;
  cout << sol.shortestPalindrome("aa") << endl;
  string s;
  for (int i = 0; i < 40000; i++) {
    s += 'a';
    if (i == 30000)
      s += "bc";
  }
  // cout << sol.shortestPalindrome(s) << endl;
  return 0;
}
