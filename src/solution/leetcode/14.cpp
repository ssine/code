#include "leetcode.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    string res = "";
    int idx = 0;
    while (true) {
      if (idx >= strs[0].size()) return res;
      char c = strs[0][idx];
      for (int ord = 1; ord < strs.size(); ord++) {
        if (idx >= strs[ord].size()) return res;
        if (strs[ord][idx] != c) return res;
      }
      res += c;
      idx ++;
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<string> arr {"","","car"};
  cout << sol.longestCommonPrefix(arr) << endl;
  return 0;
}
