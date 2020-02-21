add_executable(graph_test src/graph.cpp)
target_include_directories(graph_test PUBLIC include ../lib)
target_link_libraries(graph_test PUBLIC utils graph)

add_executable(prime_test src/prime.cpp)
target_include_directories(prime_test PUBLIC include ../lib)
target_link_libraries(prime_test PUBLIC utils number)
