#include <string>
#include <iostream>

void redirect_in_to_file(std::istream& in, std::string filename);

template <typename T>
int get_integer_num_digits(T n) {
  int cnt = 0;
  while (n != 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}
