#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<string> ans;
  void gen(string s, int l, int r) {
    if (l == 0 && r == 0) {
      ans.emplace_back(s);
      return;
    }
    if (l > 0) gen(s + '(', l - 1, r + 1);
    if (r > 0) gen(s + ')', l, r - 1);
  }
  vector<string> generateParenthesis(int n) {
    gen("", n, 0);
    return ans;
  }
};

int main() {
  Solution sol;
  print_vector(sol.generateParenthesis(3));
  return 0;
}
