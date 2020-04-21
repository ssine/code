#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  bool isMatch(string s, string p) {
    int si = 0, pi = 0;
    int lastPStarPos = -1, lastSStarPos = -1;
    while (si < s.size()) {
      char pc = p[pi], sc = s[si];
      if (pc == '?' || pc == sc) {
        pi++;
        si++;
        continue;
      }
      if (pc == '*') {
        lastPStarPos = pi;
        lastSStarPos = si;
        pi++;
        continue;
      }
      if (lastPStarPos != -1) {
        pi = lastPStarPos + 1;
        si = lastSStarPos + 1;
        lastSStarPos += 1;
        continue;
      }
      return false;
    }
    while (pi < p.size() && p[pi] == '*')
      pi++;
    return pi == p.size();
  }
};

int main() {
  Solution sol;
  cout << sol.isMatch("aa", "a") << endl;
  cout << sol.isMatch("aa", "*") << endl;
  cout << sol.isMatch("cb", "?a") << endl;
  cout << sol.isMatch("adceb", "*a*b") << endl;
  cout << sol.isMatch("acdcb", "a*c?b") << endl;
  cout << sol.isMatch(
              "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababa"
              "abbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbb"
              "aaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaab"
              "aaababaaaabb",
              "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**"
              "aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")
       << endl;
  return 0;
}