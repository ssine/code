#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    const int n = nums.size();
    if (n <= 1) return n;
    vector<set<uint64_t>> bucket(n);
    unordered_map<uint64_t, int> count;
    const int minNum = *min_element(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      uint64_t t = (int64_t)nums[i] - minNum;
      bucket[t % n].insert(t / n);
    }
    int longestNum = 0;
    for (auto b : bucket) {
      unordered_set<uint64_t> updated;
      for (uint64_t t : b) {
        updated.insert(t);
        if (count.count(t) == 0) {
          count[t] = 1;
        } else {
          count[t]++;
        }
        longestNum = max(longestNum, count[t]);
      }
      for (auto it = count.begin(); it != count.end();) {
        if (updated.count(it->first) == 0) {
          it = count.erase(it);
        } else {
          it++;
        }
      }
    }
    for (auto b : bucket) {
      unordered_set<uint64_t> updated;
      for (uint64_t t : b) {
        updated.insert(t-1);
        if (count.count(t-1) > 0)
          count[t-1]++;
        longestNum = max(longestNum, count[t-1]);
      }
      for (auto it = count.begin(); it != count.end();) {
        if (updated.count(it->first) == 0) {
          it = count.erase(it);
        } else {
          it++;
        }
      }
    }

    return longestNum;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
  cout << sol.longestConsecutive(arr) << endl;
  return 0;
}
