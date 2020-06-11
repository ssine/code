#include "leetcode.h"
#include "utils.h"

constexpr char *in20[] = {"One",     "Two",     "Three",     "Four",     "Five",    "Six",      "Seven",
                          "Eight",   "Nine",    "Ten",       "Eleven",   "Twelve",  "Thirteen", "Fourteen",
                          "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
constexpr char *in100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
  string _numberToWords(int num) {
    if (num >= 1000000000)
      return _numberToWords(num / 1000000000) + " Billion" + _numberToWords(num - 1000000000 * (num / 1000000000));
    else if (num >= 1000000)
      return _numberToWords(num / 1000000) + " Million" + _numberToWords(num - 1000000 * (num / 1000000));
    else if (num >= 1000)
      return _numberToWords(num / 1000) + " Thousand" + _numberToWords(num - 1000 * (num / 1000));
    else if (num >= 100)
      return _numberToWords(num / 100) + " Hundred" + _numberToWords(num - 100 * (num / 100));
    else if (num >= 20)
      return string(" ") + in100[num / 10 - 2] + _numberToWords(num - 10 * (num / 10));
    else if (num >= 1)
      return string(" ") + in20[num - 1];
    else
      return "";
  }

public:
  string numberToWords(int num) {
    if (num == 0)
      return "Zero";
    else
      return _numberToWords(num).substr(1);
  }
};

int main() {
  Solution sol;
  cout << sol.numberToWords(123) << endl;
  return 0;
}
