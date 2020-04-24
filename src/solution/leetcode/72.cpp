#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int minDistance(string word1, string word2) {
    size_t l1 = word1.size() + 1, l2 = word2.size() + 1;

    /**
     * ^ i
     * |
     * |-----> j
     */
    vector<vector<int>> dp(l1, vector<int>(l2));
    for (int i = 0; i < l1; i++) {
      for (int j = 0; j < l2; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = max(i, j);
          continue;
        }

        int left, down, leftDown;
        down = dp[i - 1][j] + 1;
        left = dp[i][j - 1] + 1;
        leftDown = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
        dp[i][j] = min({left, down, leftDown});
      }
    }
    return dp[l1 - 1][l2 - 1];
  }
};

int main() {
  Solution sol;
  cout << sol.minDistance("sea", "eat") << endl;
  return 0;
}
