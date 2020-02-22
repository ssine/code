#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits == "") return {};
    const static map<char, string> button_char = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    vector<string> res = {""};
    for (char d : digits) {
      vector<string> new_res;
      for (string& s : res) {
        for (char c : button_char.at(d)) {
          new_res.push_back(s + c);
        }
      }
      res = new_res;
    }
    return res;
  }
};

int main() {
  Solution sol;
  print_vector(sol.letterCombinations("23"));
  print_vector(sol.letterCombinations(""));
  return 0;
}
