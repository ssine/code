#pragma once
#include <initializer_list>

template <typename T> T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}

template <typename T> T gcd(std::initializer_list<T> args) {
  T t = *args.begin();
  for (auto next : args) {
    t = gcd(t, next);
  }
  return t;
}
