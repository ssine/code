#include "leetcode.h"
#include "utils.h"

class Solution {
  deque<int> q;

  // forward right hand side of interval
  void addBack(int n) {
    while (!q.empty() && q.back() < n) {
      q.pop_back();
    }
    q.push_back(n);
  }

  // forward left hand side of interval
  void popFront(int n) {
    if (q.empty() || n < q.front()) {
      return;
    }
    q.pop_front();
  }

public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int idx = 0;
    while (idx < k) {
      addBack(nums[idx]);
      idx++;
    }
    vector<int> ans;
    size_t n = nums.size();
    while (idx < n) {
      ans.push_back(q.front());
      addBack(nums[idx]);
      popFront(nums[idx - k]);
      idx++;
    }
    ans.push_back(q.front());
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
  print_vector(sol.maxSlidingWindow(arr, 3));
  return 0;
}
