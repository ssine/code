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

  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0)
      return 0;
    size_t n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> histogram(n, vector<int>(m));
    for (int i = 0; i < m; i++)
      histogram[0][i] = matrix[0][i] == '1' ? 1 : 0;
    int maxArea = largestRectangleArea(histogram[0]);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        histogram[i][j] = matrix[i][j] == '1' ? histogram[i - 1][j] + 1 : 0;
      }
      maxArea = max(maxArea, largestRectangleArea(histogram[i]));
    }
    return maxArea;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  cout << sol.maximalRectangle(matrix) << endl;
  return 0;
}
