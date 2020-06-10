#include "leetcode.h"
#include "utils.h"

class Solution {
  string s;
  int n;

  // return the value between pos and next unbalanced ')' or end, return the value and next pos
  pair<int, int> cal(int pos) {
    int val;
    while (pos < n && s[pos] == ' ')
      pos++;
    if (pos >= n)
      return make_pair(0, 0);
    if (isdigit(s[pos])) {
      // a ...
      int n = 1;
      while (isdigit(s[pos + n]))
        n++;
      val = stoi(s.substr(pos, n));
      pos += n;
    } else if (s[pos] == '(') {
      // ( ...
      tie(val, pos) = cal(pos + 1);
    } else if (s[pos] == ')') {
      // ... )
      return make_pair(0, pos + 1);
    }
    while (pos < n) {
      while (pos < n && s[pos] == ' ')
        pos++;
      if (s[pos] == '+' || s[pos] == '-') {
        // a +/- ...
        bool isAdd = s[pos] == '+';
        pos++;
        while (pos < n && s[pos] == ' ')
          pos++;
        if (s[pos] == '(') {
          // a +/- ( ...
          int inc;
          tie(inc, pos) = cal(pos + 1);
          if (isAdd)
            val += inc;
          else
            val -= inc;
        } else if (isdigit(s[pos])) {
          // a +/- b ...
          int n = 1;
          while (isdigit(s[pos + n]))
            n++;
          if (isAdd)
            val += stoi(s.substr(pos, n));
          else
            val -= stoi(s.substr(pos, n));
          pos += n;
        }
      } else if (s[pos] == ')') {
        // ... a )
        return make_pair(val, pos + 1);
      }
    }
    return make_pair(val, pos);
  }

public:
  int calculate(string s) {
    this->s = s;
    n = s.size();
    return cal(0).first;
  }
};

int main() {
  Solution sol;
  cout << sol.calculate("1 - (5)") << endl;
  cout << sol.calculate("0 - 1") << endl;
  cout << sol.calculate("1 + 1") << endl;
  cout << sol.calculate(" 2-1 + 2 ") << endl;
  cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  cout << sol.calculate("(((999)))") << endl;
  return 0;
}
