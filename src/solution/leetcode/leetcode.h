#include <inttypes.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
template <typename T>
struct ListNodeT {
  T val;
  ListNodeT* next;
  ListNodeT(T x) : val(x), next(nullptr) {}
};

template <typename T>
ListNodeT<T>* create_list(vector<T> list) {
  ListNodeT<T>* head = new ListNodeT<T>(0);
  auto tmp = head;
  for (auto& n : list) {
    tmp->next = new ListNodeT<T>(n);
    tmp = tmp->next;
  }
  return head->next;
}

template <typename T>
void print_list(ListNodeT<T>* head) {
  auto tmp = head;
  while (tmp) {
    cout << tmp->val;
    if (tmp->next)
      cout << "->";
    tmp = tmp->next;
  }
  cout << endl;
  return;
}

/**
 * Definition for a binary tree node.
 */
template <typename T>
struct TreeNodeT {
  T val;
  TreeNodeT<T>* left;
  TreeNodeT<T>* right;
  TreeNodeT(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <typename T>
TreeNodeT<T>* construct_tree(vector<T> list, vector<bool> isNull = {}) {
  if (list.size() == 0)
    return nullptr;
  TreeNodeT<T>* root = new TreeNodeT<T>(list[0]);
  queue<TreeNodeT<T>*> q;
  q.push(root);
  int idx = 1;
  while (idx < list.size()) {
    auto cur = q.front();
    q.pop();
    if (!cur) {
      idx++;
      continue;
    }
    if (isNull.size() > 0 && isNull[idx])
      cur->left = nullptr;
    else
      cur->left = new TreeNodeT<T>(list[idx]);
    q.push(cur->left);
    idx++;
    if (idx < list.size()) {
      if (isNull.size() > 0 && isNull[idx])
        cur->right = nullptr;
      else
        cur->right = new TreeNodeT<T>(list[idx]);
      q.push(cur->right);
      idx++;
    }
  }
  return root;
}

template <typename T>
void print_binary_tree_inorder(TreeNodeT<T>* root, bool showNull = false) {
  auto dfs = [&](auto&& self, TreeNodeT<T>* root) {
    if (!root) {
      if (showNull)
        cout << "null ";
      return;
    }
    self(self, root->left);
    cout << root->val << " ";
    self(self, root->right);
  };
  dfs(dfs, root);
  cout << endl;
}

template <typename T>
void print_binary_tree_preorder(TreeNodeT<T>* root, bool showNull = false) {
  auto dfs = [&](auto&& self, TreeNodeT<T>* root) {
    if (!root) {
      if (showNull)
        cout << "null ";
      return;
    }
    cout << root->val << " ";
    self(self, root->left);
    self(self, root->right);
  };
  dfs(dfs, root);
  cout << endl;
}

template <typename T>
void print_binary_tree_postorder(TreeNodeT<T>* root, bool showNull = false) {
  auto dfs = [&](auto&& self, TreeNodeT<T>* root) {
    if (!root) {
      if (showNull)
        cout << "null ";
      return;
    }
    self(self, root->left);
    self(self, root->right);
    cout << root->val << " ";
  };
  dfs(dfs, root);
  cout << endl;
}

template <typename T>
void print_binary_tree_bfs(TreeNodeT<T>* root, bool showNull = false) {
  queue<TreeNodeT<T>*> q;
  q.push(root);
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    if (!t) {
      if (showNull)
        cout << "null ";
      continue;
    }
    cout << t->val << " ";
    q.push(t->left);
    q.push(t->right);
  }
  cout << endl;
}
