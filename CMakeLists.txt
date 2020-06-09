cmake_minimum_required(VERSION 3.10)

# set the project name
project(code)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/lib)
add_subdirectory(src/solution)

set(do_test true)

if (do_test)
  enable_testing()
  add_subdirectory(src/test)
  add_test(graph_test graph_test)
  add_test(prime_test prime_test)
  add_test(misc_test misc_test)
endif()

