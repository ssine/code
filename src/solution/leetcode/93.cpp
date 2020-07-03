#include "leetcode.h"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12)
      return {};
    vector<string> ans;
    function<void(int, int, string)> dfs = [&](int pos, int numParts, string prefix) {
      if (numParts == 4 && prefix.size() == s.size() + 3) {
        ans.push_back(prefix);
        return;
      }
      int v;
      if (prefix.size() > 0)
        prefix += '.';
      for (int len = 1; len <= 3 && pos + len <= s.size(); len++) {
        if (len > 1 && s[pos] == '0')
          continue;
        from_chars(s.c_str() + pos, s.c_str() + pos + len, v);
        if (0 <= v && v <= 255) {
          dfs(pos + len, numParts + 1, prefix + s.substr(pos, len));
        }
      }
    };
    dfs(0, 0, "");
    return ans;
  }
};

int main() {
  Solution sol;
  print_vector(sol.restoreIpAddresses("25525511135"));
  print_vector(sol.restoreIpAddresses("010010"));
  return 0;
}
