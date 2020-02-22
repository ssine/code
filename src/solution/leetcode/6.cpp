#include "leetcode.h"

class Solution {
 public:
  string convert(string s, int numRows) {
    if (s == "" || numRows == 1) return s;
    int step = (numRows - 1) * 2;
    string target;

    for (int top = 0; top < s.size(); top += step) {
      target.push_back(s[top]);
    }

    for (int dif = numRows - 2; dif > 0; dif --) {
      for (int mid = numRows - 1; mid < s.size() + step; mid += step) {
        if (mid - dif < s.size()) target.push_back(s[mid - dif]);
        if (mid + dif < s.size()) target.push_back(s[mid + dif]);
      }
    }

    for (int bot = numRows - 1; bot < s.size(); bot += step) {
      target.push_back(s[bot]);
    }

    return target;
  }
};

int main() {
  Solution sol;
  cout << sol.convert("", 1) << endl;
  cout << sol.convert("A", 1) << endl;
  cout << sol.convert("PAYPALISHIRING", 3) << endl;
  cout << sol.convert("PAYPALISHIRING", 4) << endl;
  return 0;
}
