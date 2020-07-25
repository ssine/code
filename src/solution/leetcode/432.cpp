#include "leetcode.h"

struct CountNode {
  string s;
  int count;
  CountNode(string s) : s(s), count(1) {}
  bool operator<(const CountNode &lhs) const { return count < lhs.count; }
};

class AllOne {
  unordered_map<string, list<shared_ptr<CountNode>>::iterator> stringCountMap;
  list<shared_ptr<CountNode>> countList;

public:
  /** Initialize your data structure here. */
  AllOne() {}

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    if (stringCountMap.count(key)) {
      auto cur = stringCountMap[key];
      (*cur)->count++;
      auto it = cur;
      it++;
      while (it != countList.end() && (*it)->count < (*cur)->count) {
        iter_swap(it, cur);
        stringCountMap[(*cur)->s] = cur;
        it++;
        cur++;
      }
      stringCountMap[key] = cur;
    } else {
      countList.push_front(make_shared<CountNode>(key));
      stringCountMap[key] = countList.begin();
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    if (!stringCountMap.count(key))
      return;
    auto cur = stringCountMap[key];
    (*cur)->count--;
    if ((*cur)->count == 0) {
      stringCountMap.erase(key);
      countList.erase(cur);
      return;
    }
    if (cur == countList.begin())
      return;
    auto it = cur;
    it--;
    while (cur != countList.begin() && (*it)->count > (*cur)->count) {
      iter_swap(it, cur);
      stringCountMap[(*cur)->s] = cur;
      it--;
      cur--;
    }
    stringCountMap[key] = cur;
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if (countList.size() == 0)
      return "";
    return countList.back()->s;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if (countList.size() == 0)
      return "";
    return countList.front()->s;
  }
};

int main() {
  AllOne *obj = new AllOne();
  obj->inc("a");
  obj->inc("b");
  obj->inc("b");
  obj->inc("c");
  obj->inc("c");
  obj->inc("c");
  obj->dec("b");
  obj->dec("b");
  cout << obj->getMinKey() << endl; // a
  obj->dec("a");
  cout << obj->getMaxKey() << endl; // c
  cout << obj->getMinKey() << endl; // c
  return 0;
}
