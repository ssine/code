#include "leetcode.h"

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    if (nums.size() < 3)
      return false;
    stack<pair<int, int>> st;
    int vmax = nums[0], vmin = nums[0];
    for (int num : nums) {
      if (vmin < num && num < vmax) {
        return true;
      } else if (num >= vmax) {
        vmax = num;
        while (!st.empty()) {
          if (st.top().first < vmax && vmax < st.top().second) {
            return true;
          } else if (vmax <= st.top().first) {
            break;
          } else {
            st.pop();
          }
        }
      } else {
        st.push(make_pair(vmin, vmax));
        vmin = vmax = num;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  // vector<int> arr = {1, 10, -100, -90, -50, -20, -200, 5};
  vector<int> arr = {3, 1, 4, 2};
  cout << sol.find132pattern(arr) << endl;
  return 0;
}
