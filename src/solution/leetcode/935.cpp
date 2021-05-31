#include "leetcode.h"

class Solution {
public:
  int knightDialer(int n) {
    vector<vector<int>> dp(n, vector<int>(10, 1));
    vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {7, 0, 1}, {2, 6}, {1, 3}, {2, 4}};
    int mod = 1e9 + 7;
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < 10; j++) {
        dp[i][j] = 0;
        for (int m : moves[j]) {
          dp[i][j] = (dp[i][j] + dp[i + 1][m]) % mod;
        }
      }
    }
    return accumulate(dp[0].begin(), dp[0].end(), 0, [&](int acc, int b) { return (acc + b) % mod; });
  }
};