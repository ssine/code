#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    int lastMin = prices[0];
    int lastMax = 0;
    for (int idx = 0; idx < prices.size(); idx++) {
      if (idx == prices.size() - 1 || prices[idx] > prices[idx + 1]) {
        profit += prices[idx] - lastMin;
        if (idx < prices.size() - 1)
          lastMin = prices[idx + 1];
      } else {
        lastMax = prices[idx];
      }
    }
    return profit;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {7, 6, 4, 3, 1};
  cout << sol.maxProfit(arr) << endl;
  return 0;
}
