#pragma once

#include <iostream>
#include <string>
#include <vector>

void redirect_in_to_file(std::istream &in, std::string filename);

template <typename T> void print_vector(std::vector<T> vec, std::string sep = " ") {
  std::cout << "[";
  bool is_first = true;
  for (auto &v : vec) {
    if (!is_first)
      cout << sep;
    is_first = false;
    std::cout << v;
  }
  std::cout << "]\n";
}

template <typename T> void print_matrix(std::vector<std::vector<T>> &mat) {
  for (auto &line : mat) {
    for (auto &v : line) {
      std::cout << v << "\t";
    }
    std::cout << std::endl;
  }
}

template <typename T> int get_integer_num_digits(T n) {
  int cnt = 0;
  while (n != 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

std::vector<std::string_view> split_string(std::string_view strv, std::string_view delims = " ");
