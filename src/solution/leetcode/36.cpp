#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
#define check(i, j)                \
  {                                \
    if (board[i][j] == '.')        \
      continue;                    \
    uint8_t n = board[i][j] - '0'; \
    if (exist_nums.count(n) != 0)  \
      return false;                \
    exist_nums.insert(n);          \
  }
    unordered_set<uint8_t> exist_nums;
    for (int row = 0; row < 9; row += 3) {
      for (int col = 0; col < 9; col += 3) {
        exist_nums.clear();
        for (int i = row; i < row + 3; i++) {
          for (int j = col; j < col + 3; j++) {
            check(i, j);
          }
        }
      }
    }

    for (int row = 0; row < 9; row++) {
      exist_nums.clear();
      for (int i = 0; i < 9; i++) {
        check(row, i);
      }
    }

    for (int col = 0; col < 9; col++) {
      exist_nums.clear();
      for (int i = 0; i < 9; i++) {
        check(i, col);
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '9', '9'}};
  print_matrix(board);
  cout << sol.isValidSudoku(board) << endl;
  return 0;
}
