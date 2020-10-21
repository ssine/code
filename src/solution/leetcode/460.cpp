#include "leetcode.h"

class LFUCache {
  struct KeyInfo {
    int val, lastOpRank, frequency;
  };
  int capacity;
  int opCount;
  unordered_map<int, KeyInfo> kvStore;
  map<int, int> rIndex;

  inline int getReverseKey(KeyInfo &info) { return info.frequency * 100000 + info.lastOpRank; }

public:
  LFUCache(int capacity) : capacity(capacity), opCount(0) {}

  int get(int key) {
    if (!kvStore.count(key))
      return -1;
    auto &info = kvStore[key];
    int prevRKey = getReverseKey(info);
    info.frequency++;
    info.lastOpRank = opCount;
    int nextRKey = getReverseKey(info);
    rIndex.erase(prevRKey);
    rIndex[nextRKey] = key;
    opCount++;
    return info.val;
  }

  void put(int key, int value) {
    if (kvStore.count(key)) {
      // existing: update like get
      auto &info = kvStore[key];
      int prevRKey = getReverseKey(info);
      info.frequency++;
      info.lastOpRank = opCount;
      info.val = value;
      int nextRKey = getReverseKey(info);
      rIndex.erase(prevRKey);
      rIndex[nextRKey] = key;
    } else {
      // new key: evict and insert
      if (kvStore.size() == capacity) {
        if (capacity == 0)
          return;
        int keyToEvict = rIndex.begin()->second;
        kvStore.erase(keyToEvict);
        rIndex.erase(rIndex.begin());
      }
      KeyInfo info;
      info.val = value;
      info.frequency = 1;
      info.lastOpRank = opCount;
      int rKey = getReverseKey(info);
      kvStore[key] = info;
      rIndex[rKey] = key;
    }
    opCount++;
  }
};

int main() {
  LFUCache *obj = new LFUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  cout << obj->get(3) << endl;
  obj->put(4, 4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;
  return 0;
}
