#include "leetcode.h"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    vector<unordered_map<int64_t, int>> dp(A.size());
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
      for (int j = 0; j < i; j++) {
        int64_t interval = static_cast<int64_t>(A[i]) - A[j];
        ans += dp[j][interval];
        dp[i][interval] += dp[j][interval] + 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 4, 6, 8, 10};
  cout << sol.numberOfArithmeticSlices(arr) << endl;
  return 0;
}
