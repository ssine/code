#pragma once
#include "graph.h"

/**
 * Directed Graph
 */
template <class vertex_type, class edge_type = int>
class digraph: public graph<vertex_type, edge_type> {
 public:
  void add_edge(vertex_type from, vertex_type to);
  void add_edge(vertex_type from, vertex_type to, edge_type v);
  // TODO: indegree and outdegree
};

template <class vertex_type, class edge_type>
void digraph<vertex_type, edge_type>::add_edge(vertex_type from, vertex_type to) {
  auto& vf = vtx_map.find(from)->second;
  auto& vt = vtx_map.find(to)->second;
  edges.emplace_back(std::make_shared<edge>(vt));
  vf->edges.emplace_back(edges.back());
}

template <class vertex_type, class edge_type>
void digraph<vertex_type, edge_type>::add_edge(vertex_type from,
                                             vertex_type to,
                                             edge_type v) {
  auto& vf = vtx_map.find(from)->second;
  auto& vt = vtx_map.find(to)->second;
  edges.emplace_back(std::make_shared<edge>(vt, v));
  vf->edges->emplace_back(edges.back());
}
