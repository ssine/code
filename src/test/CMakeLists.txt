add_executable(graph_test src/graph.cpp)
target_include_directories(graph_test PUBLIC include ../lib)
target_link_libraries(graph_test PUBLIC utils graph)

add_executable(number_test src/number.cpp)
target_include_directories(number_test PUBLIC include ../lib)
target_link_libraries(number_test PUBLIC utils number)

add_executable(misc_test src/misc.cpp)
target_include_directories(misc_test PUBLIC include ../lib)
target_link_libraries(misc_test PUBLIC utils misc)
