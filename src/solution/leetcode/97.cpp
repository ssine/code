#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    size_t l1 = s1.size(), l2 = s2.size();
    if (l1 + l2 != s3.size())
      return false;
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
    for (int i = 0; i < l1 + 1; i++) {
      for (int j = 0; j < l2 + 1; j++) {
        if (i == 0 && j == 0)
          dp[i][j] = true;
        else if (i == 0)
          dp[i][j] = dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];
        else if (j == 0)
          dp[i][j] = dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
        else
          dp[i][j] = (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) ||
                     (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
      }
    }
    return dp[l1][l2];
  }
};

int main() {
  Solution sol;
  cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
  return 0;
}
