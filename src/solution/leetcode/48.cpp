#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        int t = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = t;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> arr = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  sol.rotate(arr);
  arr = {
  {1,2,3},
  {4,5,6},
  {7,8,9}
};
  sol.rotate(arr);
  print_matrix(arr);
  return 0;
}