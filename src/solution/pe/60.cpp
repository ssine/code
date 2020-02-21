/**
 * https://projecteuler.net/problem=60
 */
#include <cmath>
#include <iostream>
#include <numeric>
#include "graph.h"
#include "prime.h"

using namespace std;

typedef prime<int> primei;

const int N = 10000;

int digit_num(int n) {
  int cnt = 0;
  while (n) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

bool is_pair_prime(int a, int b) {
  return primei::is_prime(a + b * static_cast<int>(pow(10, digit_num(a)))) &&
         primei::is_prime(b + a * static_cast<int>(pow(10, digit_num(b))));
}

int main() {
  primei::pre_compute(N);
  graph<int> g;
  vector<int> prime_list;
  for (int i = 2; i < N; i++) {
    if (primei::is_prime(i)) {
      prime_list.push_back(i);
      g.add_vertex(i);
    }
  }
  for (int i = 0; i < prime_list.size(); i++) {
    for (int j = i + 1; j < prime_list.size(); j++) {
      if (is_pair_prime(prime_list[i], prime_list[j])) {
        g.add_edge(prime_list[i], prime_list[j]);
      }
    }
  }
  cout << "edges added.\n";
  auto res = g.find_max_clique();
  for (auto& v : res) {
    cout << v << " ";
  }
  cout << "\n" << std::accumulate(res.begin(), res.end(), 0);
  return 0;
}
