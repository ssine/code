#include "leetcode.h"

class Solution {
  double radius, cx, cy;
  default_random_engine rng;
  uniform_real_distribution<double> dist;

public:
  Solution(double radius, double x_center, double y_center)
      : radius(radius), cx(x_center), cy(y_center), dist(-radius, radius) {}

  vector<double> randPoint() {
    double x, y;
    do {
      x = dist(rng), y = dist(rng);
    } while (x * x + y * y > radius * radius);
    return {x + cx, y + cy};
  }
};

int main() {
  Solution sol(1234793.7, 73839.1, 3289891.3);
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  print_vector(sol.randPoint());
  return 0;
}
