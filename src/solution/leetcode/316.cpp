#include "leetcode.h"

class Solution {
public:
  string removeDuplicateLetters(string s) {
    multiset<char> pending(s.begin(), s.end());
    set<char> inserted;
    string ans = "0";
    for (char c : s) {
      pending.erase(pending.find(c));
      if (inserted.count(c)) continue;
      while (c < ans.back() && pending.count(ans.back())) {
        inserted.erase(ans.back());
        ans.pop_back();
      }
      ans += c;
      inserted.insert(c);
    }
    return ans.substr(1);
  }
};

int main() {
  Solution sol;
  cout << sol.removeDuplicateLetters("bcabc") << endl;
  cout << sol.removeDuplicateLetters("cbacdcbc") << endl;
  return 0;
}
