#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    size_t n = heights.size();
    stack<int> incIdxs;
    int idx = 0, maxArea = 0;
    while (idx < n) {
      if (incIdxs.empty() || heights[idx] > heights[incIdxs.top()]) {
        incIdxs.push(idx);
        idx++;
      } else {
        int height = heights[incIdxs.top()];
        incIdxs.pop();
        int leftIdx = incIdxs.empty() ? -1 : incIdxs.top();
        maxArea = max(maxArea, height * (idx - (leftIdx + 1)));
      }
    }
    return maxArea;
  }
};

int main() {
  Solution sol;
  vector<int> heights = {4, 2, 0, 3, 2, 5};
  cout << sol.largestRectangleArea(heights) << endl;
  return 0;
}
