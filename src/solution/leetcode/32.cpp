#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s == "") return 0;
    vector<int> longest_ends_at(s.size(), 0);
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(') longest_ends_at[i] = 0;
      else if (i > 0) {
        if (s[i - 1] == '(') longest_ends_at[i] = i >= 2 ? longest_ends_at[i - 2] + 2 : 2;
        else if (i > longest_ends_at[i - 1]) {
          if (s[i - longest_ends_at[i - 1] - 1] == '(') {
            longest_ends_at[i] = longest_ends_at[i - 1] + 2;
            if (i > longest_ends_at[i - 1] + 1)
              longest_ends_at[i] += longest_ends_at[i - longest_ends_at[i - 1] - 2];
          }
        }
      }
    }
    return *max_element(longest_ends_at.begin(), longest_ends_at.end());
  }
};

int main() {
  Solution sol;
  cout << sol.longestValidParentheses("") << endl;
  cout << sol.longestValidParentheses("(()") << endl;
  cout << sol.longestValidParentheses(")()())") << endl;
  cout << sol.longestValidParentheses("(()())") << endl;
  cout << sol.longestValidParentheses("()(())") << endl;
  cout << sol.longestValidParentheses("()()))))()()(") << endl;
  return 0;
}
