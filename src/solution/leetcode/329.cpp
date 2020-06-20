#include "leetcode.h"

class Solution {
  vector<vector<int>> pathLen;
  vector<vector<int>> matrix;
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int n, m;

  // get the length of longest increasing path ending at (x, y)
  int getPathLen(int x, int y) {
    if (pathLen[x][y] != -1)
      return pathLen[x][y];
    int maxPrevLen = 0;
    for (auto [dx, dy] : directions) {
      int tx = x + dx;
      int ty = y + dy;
      if (0 <= tx && tx < n && 0 <= ty && ty < m && matrix[x][y] < matrix[tx][ty]) {
        maxPrevLen = max(maxPrevLen, getPathLen(tx, ty));
      }
    }
    pathLen[x][y] = maxPrevLen + 1;
    return pathLen[x][y];
  }

public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    this->matrix = matrix;
    n = matrix.size();
    if (n == 0)
      return 0;
    m = matrix[0].size();
    pathLen = vector<vector<int>>(n, vector<int>(m, -1));
    int maxPathLen = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        maxPathLen = max(maxPathLen, getPathLen(i, j));
      }
    }
    return maxPathLen;
  }
};

int main() {
  Solution sol;
  // vector<vector<int>> arr = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  vector<vector<int>> arr = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
  cout << sol.longestIncreasingPath(arr) << endl;
  return 0;
}
