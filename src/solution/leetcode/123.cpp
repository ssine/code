#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    vector<int> leftProfit = vector<int>(prices.size() + 1, 0);
    vector<int> rightProfit = vector<int>(prices.size() + 1, 0);
    int lastMin = numeric_limits<int>::max();
    for (int idx = 0; idx < prices.size(); idx++) {
      lastMin = min(lastMin, prices[idx]);
      leftProfit[idx + 1] = max(leftProfit[idx], prices[idx] - lastMin);
    }
    int lastMax = numeric_limits<int>::min();
    for (int idx = prices.size() - 1; idx >= 0; idx--) {
      lastMax = max(lastMax, prices[idx]);
      rightProfit[idx] = max(rightProfit[idx + 1], lastMax - prices[idx]);
    }
    int profit = 0;
    for (int divider = 0; divider <= prices.size(); divider++) {
      profit = max(profit, leftProfit[divider] + rightProfit[divider]);
    }
    return profit;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {7,6,4,3,1};
  cout << sol.maxProfit(arr) << endl;
  return 0;
}
