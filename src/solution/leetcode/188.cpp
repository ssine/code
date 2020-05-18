#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int maxProfit = 0;
    int n = prices.size();

    if (n < 2)
      return 0;
    if (k > n / 2) {
      for (int i = 1; i < n; i++)
        maxProfit += max(prices[i] - prices[i - 1], 0);
      return maxProfit;
    }

    vector<vector<int>> dp (k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++) {
      int localMax = dp[i - 1][0] - prices[0];
      for (int j = 1; j < n; j++) {
        dp[i][j] = max(dp[i][j-1], prices[j] + localMax);
        localMax = max(localMax, dp[i - 1][j] - prices[j]);
      }
    }
    return dp[k][n-1];
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3,2,6,5,0,3};
  cout << sol.maxProfit(2, arr) << endl;
  return 0;
}
