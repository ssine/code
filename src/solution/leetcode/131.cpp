#include "leetcode.h"
#include "utils.h"

class Solution {
  string s;
  int n;
  vector<vector<string>> ans;
  vector<string> tmp;
  vector<vector<bool>> isPalindrome;

public:
  void _generateIsPalindrome() {
    for (int i = 0; i < n; i++) {
      isPalindrome[i][i] = true;
      if (i != n - 1)
        isPalindrome[i][i + 1] = s[i] == s[i + 1];
    }
    for (int len = 2; len < n; len++) {
      for (int i = 0; i + len < n; i++) {
        isPalindrome[i][i + len] = isPalindrome[i + 1][i + len - 1] && s[i] == s[i + len];
      }
    }
  }

  void _partition(int startIdx) {
    if (startIdx == n) {
      ans.push_back(tmp);
    }
    for (int i = startIdx; i < n; i++) {
      if (isPalindrome[startIdx][i]) {
        tmp.push_back(s.substr(startIdx, i + 1 - startIdx));
        _partition(i + 1);
        tmp.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    this->s = s;
    n = s.size();
    isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
    _generateIsPalindrome();
    _partition(0);
    return ans;
  }
};

int main() {
  Solution sol;
  print_matrix(sol.partition("efe"));
  return 0;
}
