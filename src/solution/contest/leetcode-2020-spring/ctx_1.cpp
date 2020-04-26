#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int expectNumber(vector<int>& scores) {
    sort(scores.begin(), scores.end());
    auto it = unique(scores.begin(), scores.end());
    return it - scores.begin();
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 1, 2};
  cout << sol.expectNumber(arr) << endl;
  return 0;
}
