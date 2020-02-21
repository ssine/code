#pragma once
#include <iostream>
#include <map>
#include <set>
#include <optional>
#include <vector>
#include <iterator>
#include <functional>

/**
 * Undirected Graph
 */
template <class vertex_type, class edge_type = int>
class graph {
 protected:
  struct vertex;
  struct edge;
  struct adjacent_vertices;

  std::map<vertex_type, std::shared_ptr<vertex>> vtx_map;
  std::vector<std::shared_ptr<vertex>> vertices;
  std::vector<std::shared_ptr<edge>> edges;

 public:
  void add_vertex(vertex_type vtx);
  /**
   * each edge should be added only once
   */
  void add_edge(vertex_type from, vertex_type to);
  void add_edge(vertex_type from, vertex_type to, edge_type edge);

  bool have_edge(vertex_type from, vertex_type to);
  edge_type get_edge(vertex_type from, vertex_type to);
  std::optional<edge_type> get_edge_optional(vertex_type from, vertex_type to);

  adjacent_vertices get_adjacent_vertices(vertex_type vtx);

  size_t degree(vertex_type vtx);

  std::set<vertex_type> find_max_clique();
};

template <class vertex_type, class edge_type>
struct graph<vertex_type, edge_type>::vertex {
  vertex_type value;
  std::vector<std::shared_ptr<edge>> edges;
  vertex() {}
  vertex(vertex_type v) : value(v) {}
  friend std::ostream& operator<<(std::ostream& os, vertex& v);
};

template <class vertex_type, class edge_type>
std::ostream& operator<<(std::ostream& os,
                         typename graph<vertex_type, edge_type>::vertex& v) {
  os << v.value;
  return os;
}

template <class vertex_type, class edge_type>
struct graph<vertex_type, edge_type>::edge {
  edge_type value;
  std::shared_ptr<vertex> to;
  edge() {}
  edge(std::shared_ptr<vertex> to) : to(to) {}
  edge(edge_type v) : value(v) {}
  edge(std::shared_ptr<vertex> to, edge_type v) : to(to), value(v) {}
};

template <class vertex_type, class edge_type>
void graph<vertex_type, edge_type>::add_vertex(vertex_type vtx) {
  if (vtx_map.find(vtx) != vtx_map.end())
    return;
  vertices.emplace_back(std::make_shared<vertex>(vtx));
  vtx_map[vtx] = vertices.back();
}

template <class vertex_type, class edge_type>
void graph<vertex_type, edge_type>::add_edge(vertex_type from, vertex_type to) {
  auto& vf = vtx_map.find(from)->second;
  auto& vt = vtx_map.find(to)->second;
  edges.emplace_back(std::make_shared<edge>(vt));
  vf->edges.emplace_back(edges.back());
  edges.emplace_back(std::make_shared<edge>(vf));
  vt->edges.emplace_back(edges.back());
}

template <class vertex_type, class edge_type>
void graph<vertex_type, edge_type>::add_edge(vertex_type from,
                                             vertex_type to,
                                             edge_type v) {
  auto& vf = vtx_map.find(from)->second;
  auto& vt = vtx_map.find(to)->second;
  edges.emplace_back(std::make_shared<edge>(vt, v));
  vf->edges.emplace_back(edges.back());
  edges.emplace_back(std::make_shared<edge>(vf, v));
  vt->edges.emplace_back(edges.back());
}

template <class vertex_type, class edge_type>
bool graph<vertex_type, edge_type>::have_edge(vertex_type from,
                                              vertex_type to) {
  auto& vf = vtx_map.find(from)->second;
  for (auto& e : vf->edges) {
    if (e->to->value == to)
      return true;
  }
  return false;
}

template <class vertex_type, class edge_type>
edge_type graph<vertex_type, edge_type>::get_edge(vertex_type from,
                                                  vertex_type to) {
  auto& vf = vtx_map.find(from)->second;
  for (auto& e : vf->edges) {
    if (e->to->value == to)
      return e->value;
  }
  throw "Edge not found!";
}

template <class vertex_type, class edge_type>
std::optional<edge_type> graph<vertex_type, edge_type>::get_edge_optional(
    vertex_type from,
    vertex_type to) {
  auto& vf = vtx_map.find(from)->second;
  for (auto& e : vf->edges) {
    if (e->to->value == to)
      return e->value;
  }
  return std::nullopt;
}

template <class vertex_type, class edge_type>
size_t graph<vertex_type, edge_type>::degree(vertex_type vtx) {
  auto& v = vtx_map.find(vtx)->second;
  return v->edges.size();
}

template <class vertex_type, class edge_type>
struct graph<vertex_type, edge_type>::adjacent_vertices {
  std::vector<std::shared_ptr<edge>>* edges_ptr;

  class iterator {
    typename std::vector<std::shared_ptr<edge>>::iterator it;

   public:
    typedef std::random_access_iterator_tag iterator_category;

    iterator(){};
    iterator(const iterator& iter) : it(iter.it){};
    iterator(const typename std::vector<std::shared_ptr<edge>>::iterator it)
        : it(it){};

    iterator& operator=(const iterator& iter) { it = iter.it; };
    bool operator==(const iterator& iter) const { return it == iter.it; };
    bool operator!=(const iterator& iter) const { return it != iter.it; };
    bool operator<(const iterator&) const { return it < iter.it; };
    bool operator>(const iterator&) const { return it > iter.it; };
    bool operator<=(const iterator&) const { return it <= iter.it; };
    bool operator>=(const iterator&) const { return it >= iter.it; };

    iterator& operator++() {
      it++;
      return *this;
    };
    iterator operator++(int) {
      auto t = *this;
      it++;
      return t;
    };
    iterator& operator+=(size_t size) {
      it += size;
      return *this;
    };
    iterator operator+(size_t size) const {
      auto t = *this;
      t.it += size;
      return t;
    };

    vertex_type& operator*() const { return (*it)->to->value; };
    vertex_type* operator->() const { return &((*it)->to->value); };
  };

  iterator begin() {
    iterator it(edges_ptr->begin());
    return it;
  }
  iterator end() {
    iterator it(edges_ptr->end());
    return it;
  }
  vertex_type& operator[](int sub) { return (*edges_ptr)[sub]->to->value; }
};

template <class vertex_type, class edge_type>
typename graph<vertex_type, edge_type>::adjacent_vertices
graph<vertex_type, edge_type>::get_adjacent_vertices(vertex_type vtx_value) {
  auto& vtx = vtx_map.find(vtx_value)->second;
  adjacent_vertices adjv;
  adjv.edges_ptr = &(vtx->edges);
  return adjv;
}

/**
 * Algorithms
 */

/**
 * Find Max Clique: Bron-Kerbosch Algorithm
 */
template <class vertex_type, class edge_type>
typename std::set<vertex_type>
graph<vertex_type, edge_type>::find_max_clique() {
  typedef std::shared_ptr<vertex> node;
  struct node_cmp {
    bool operator()(const node& lhs, const node& rhs) const {
      return lhs.owner_before(rhs);
    }
  };
  auto cmp = [](node a, node b) { return a.owner_before(b); };
  typedef std::set<node, node_cmp> nset;

  auto set_union = [&] (nset a, nset b) -> nset {
    nset c;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.end()), cmp);
    return c;
  };
  auto set_intersection = [&] (nset a, nset b) -> nset {
    nset c;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.end()), cmp);
    return c;
  };
  auto set_difference = [&] (nset a, nset b) -> nset {
    nset c;
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.end()), cmp);
    return c;
  };

  size_t max_num = 0;
  nset max_set;

  std::function<void(nset&, nset&, nset&)> bron_kerbosch;
  bron_kerbosch = [&] (nset& real, nset& pending, nset& excluded) {
    if (pending.empty() && excluded.empty()) {
      if (real.size() > max_num) {
        max_num = real.size();
        max_set = real;
      }
    }
    nset::iterator v = pending.begin();
    while (!pending.empty() && v != pending.end()) {
      nset vset;
      vset.insert(*v);
      nset n;
      for (auto& ne : (*v)->edges) {
        n.insert(ne->to);
      }
      bron_kerbosch(set_union(real, vset), set_intersection(pending, n), set_intersection(excluded, n));
      pending = set_difference(pending, vset);
      excluded = set_union(excluded, vset);
      if (!pending.empty()) {
        v = pending.begin();
      }
    }
  };

  nset rl;
  nset pd = { vertices.begin(), vertices.end() };
  nset ex;
  bron_kerbosch(rl, pd, ex);

  std::set<vertex_type> result;
  for (auto& v : max_set) {
    result.insert(v->value);
  }

  return result;
}
