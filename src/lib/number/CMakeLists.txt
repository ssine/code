add_library(number
  include/prime.h
  src/prime.cpp)

target_include_directories(number PUBLIC include)
