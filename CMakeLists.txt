cmake_minimum_required(VERSION 3.10)

# set the project name
project(code)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src/lib)

set(run_topic false)

if (run_topic)
add_subdirectory(src/topic)
else()
add_subdirectory(src/solution)
endif()

set(do_test false)

if (do_test)
  enable_testing()
  add_subdirectory(src/test)
  add_test(graph_test graph_test)
  add_test(prime_test prime_test)
  add_test(misc_test misc_test)
endif()

