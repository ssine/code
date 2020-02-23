#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  bool isValid(string s) {
    static const map<char, char> l_pair = {
      {')', '('},
      {']', '['},
      {'}', '{'},
    };

    stack<char> st;
    for (char& c : s) {
      if (c == ')' || c == ']' || c == '}') {
        if (st.empty() || st.top() != l_pair.at(c)) return false;
        st.pop();
      } else {
        st.push(c);
      }
    }
    return st.empty();
  }
};

int main() {
  Solution sol;
  cout << sol.isValid("()") << endl;
  cout << sol.isValid("()[]{}") << endl;
  cout << sol.isValid("(]") << endl;
  cout << sol.isValid("([)]") << endl;
  cout << sol.isValid("{[]}") << endl;
  cout << sol.isValid("]") << endl;
  return 0;
}
