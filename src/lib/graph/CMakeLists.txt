add_library(graph
  include/graph.h
  include/digraph.h
  src/graph.cpp
  )

target_include_directories(graph PUBLIC include)
