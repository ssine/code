#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> res(people.size(), vector<int>());
    sort(people.begin(), people.end(),
         [](auto &lhs, auto &rhs) { return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0]; });
    for (auto &p : people) {
      int idx_cnt = p[1], idx = 0;
      while (idx < people.size()) {
        if (res[idx].size() != 0 && res[idx][0] < p[0]) {
          idx++;
          continue;
        }
        if (idx_cnt == 0) {
          res[idx] = p;
          break;
        } else {
          idx_cnt--;
          idx++;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> arr = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  print_matrix(sol.reconstructQueue(arr));
  return 0;
}
