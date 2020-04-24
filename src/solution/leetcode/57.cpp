#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    if (intervals.size() == 0)
      return {newInterval};

    auto lit =
        lower_bound(intervals.begin(), intervals.end(), newInterval,
                    [](auto& itv, auto& val) { return itv[1] < val[0]; });
    auto uit =
        upper_bound(intervals.begin(), intervals.end(), newInterval,
                    [](auto& val, auto& itv) { return val[1] < itv[0]; });

    if (lit == intervals.end()) {
      intervals.insert(lit, newInterval);
      return intervals;
    }
    if (uit == intervals.begin()) {
      intervals.insert(uit, newInterval);
      return intervals;
    }

    int l = min((*lit)[0], newInterval[0]);
    int r = max((*(uit - 1))[1], newInterval[1]);
    auto insPos = intervals.erase(lit, uit);
    intervals.insert(insPos, {l, r});
    return intervals;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> arr = {};
  vector<int> newInterval = {1, 2};
  print_matrix(sol.insert(arr, newInterval));
  return 0;
}
