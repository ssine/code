#include "leetcode.h"
#include "utils.h"

class Solution {
  string s;
  int n;
  vector<vector<bool>> isPalindrome;
  vector<int> minCutNum;

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

  int minCut(string s) {
    this->s = s;
    n = s.size();
    isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
    _generateIsPalindrome();

    // minCutNum[i] means min cut of s[0:i)
    minCutNum = vector<int>(n + 1, n - 1);
    minCutNum[0] = -1;
    minCutNum[1] = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (isPalindrome[j][i - 1])
          minCutNum[i] = min(minCutNum[i], minCutNum[j] + 1);
      }
    }
    return minCutNum[n];
  }
};

int main() {
  Solution sol;
  cout << sol.minCut("aab") << endl;
  cout << sol.minCut("efe") << endl;
  cout << sol.minCut(
              "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi")
       << endl;
  return 0;
}
