#include "leetcode.h"

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int s1Num = 1, s2Num = 1, s1Pos = 0, s2Pos = 0;
    set<int> s1EndPos;
    while (!(s1Pos == s1.size() && s2Pos == s2.size())) {
      if (s1Pos == s1.size()) {
        s1Pos = 0;
        s1Num++;
      }
      if (s2Pos == s2.size()) {
        s2Pos = 0;
        s2Num++;
        if (s1EndPos.count(s1Pos)) {
          // a loop
          s1Num++;
          break;
        } else {
          s1EndPos.insert(s1Pos);
        }
      }
      if (s1[s1Pos] == s2[s2Pos]) {
        s2Pos++;
      }
      s1Pos++;
    }
    int maxNs2 = n1 * s2Num / s1Num;
    return maxNs2 / n2;
  }
};

int main() {
  Solution sol;
  // cout << sol.getMaxRepetitions("acb", 4, "ab", 2) << endl;
  // cout << sol.getMaxRepetitions("aaa", 3, "aa", 1) << endl;
  // cout << sol.getMaxRepetitions("baba", 11, "baab", 1) << endl;
  cout << sol.getMaxRepetitions("niconiconi", 99981, "nico", 81) << endl;
  return 0;
}
