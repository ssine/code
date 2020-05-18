#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    int lastMin = numeric_limits<int>::max();
    for (auto p : prices) {
      lastMin = min(lastMin, p);
      profit = max(profit, p - lastMin);
    }
    return profit;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2};
  cout << sol.maxProfit(arr) << endl;
  return 0;
}
