#pragma once
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

template <typename T>
class prime {
 private:
  static std::set<T> primes, non_primes;
  static int prime_known_range;
  static bool is_prime_naive(T num);

 public:
  /**
   * Pre-compute primes in range [0, range]
   */
  static void pre_compute(int range);
  static bool is_prime(T num);
};

template<typename T> int prime<T>::prime_known_range = 0;
template<typename T> std::set<T> prime<T>::primes;
template<typename T> std::set<T> prime<T>::non_primes;

template <typename T>
void prime<T>::pre_compute(int range) {
  std::vector<bool> is_p(range, true);
  for (int i = 2; i < range; i++) {
    if (is_p[i]) {
      for (int j = i + i; j < range; j += i) {
        is_p[j] = false;
      }
      primes.insert(i);
    }
  }
  prime_known_range = std::max(prime_known_range, range);
}

template <typename T>
bool prime<T>::is_prime(T num) {
  if (num < prime_known_range) {
    return primes.count(num) == 1;
  }
  if (primes.count(num) == 1)
    return true;
  if (non_primes.count(num) == 1)
    return false;
  bool isp = is_prime_naive(num);
  if (isp)
    primes.insert(num);
  else
    non_primes.insert(num);
  return isp;
}

template <typename T>
bool prime<T>::is_prime_naive(T num) {
  if (num == 2 || num == 3)
    return true;
  if (num == 1 || num % 2 == 0 || num % 3 == 0)
    return false;
  const double sqrt_num = std::sqrt(num * 1.0);
  for (int i = 5; i <= sqrt_num; i += 6)
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  return true;
}
