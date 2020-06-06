add_library(number
  include/number.h
  include/prime.h
  src/number.cpp
  src/prime.cpp
  )

target_include_directories(number PUBLIC include)
