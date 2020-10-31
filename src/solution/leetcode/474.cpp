#include "leetcode.h"

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> cnts;
    transform(strs.begin(), strs.end(), back_inserter(cnts), [](string &str) {
      return make_pair(count(str.begin(), str.end(), '0'), count(str.begin(), str.end(), '1'));
    });
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (auto &[n0, n1] : cnts) {
      for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
          if (i - n0 >= 0 && j - n1 >= 0) {
            dp[i][j] = max(dp[i][j], dp[i - n0][j - n1] + 1);
          }
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution sol;
  vector<string> arr = {"10", "0001", "111001", "1", "0"};
  cout << sol.findMaxForm(arr, 5, 3) << endl;
  // vector<string> arr = {"10","0","1"};
  // cout << sol.findMaxForm(arr, 1, 1) << endl;
  return 0;
}
