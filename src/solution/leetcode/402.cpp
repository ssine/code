#include "leetcode.h"

class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans;
    for (char c : num) {
      while (!ans.empty() && ans.back() > c && k > 0) {
        ans.pop_back();
        k--;
      }
      ans.push_back(c);
    }
    ans.erase(ans.size() - k);
    while (ans.size() > 0 && ans[0] == '0')
      ans.erase(ans.begin());
    if (ans.size() == 0)
      ans = "0";
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.removeKdigits("1432219", 3) << endl;
  cout << sol.removeKdigits("10200", 1) << endl;
  cout << sol.removeKdigits("10", 2) << endl;
  cout << sol.removeKdigits("1234567890", 9) << endl;
  return 0;
}
