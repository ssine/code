#include "utils.h"
#include <algorithm>
#include <fstream>

using namespace std;

void redirect_in_to_file(istream &in, string filename) {
  static ifstream fin;
  fin.open(filename);
  in.rdbuf(fin.rdbuf());
}

vector<string_view> split_string(string_view strv, string_view delims) {
  vector<string_view> output;
  size_t first = 0;
  while (first < strv.size()) {
    const auto second = strv.find_first_of(delims, first);
    if (first != second)
      output.emplace_back(strv.substr(first, second - first));
    if (second == string_view::npos)
      break;
    first = second + 1;
  }
  return output;
}
