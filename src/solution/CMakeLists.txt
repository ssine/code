# add the executable
add_executable(main leetcode/486.cpp)
target_include_directories(main PUBLIC ../lib)
target_link_libraries(main PUBLIC utils graph number)
