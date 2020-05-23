#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, int> wordToId;
    wordList.push_back(beginWord);
    const int n = wordList.size();
    for (int i = 0; i < n; i++)
      wordToId[wordList[i]] = i;
    if (wordToId.count(endWord) == 0)
      return {};

    struct node {
      vector<int> edges;
      vector<int> backTraceEdges;
      node() {}
    };
    vector<node> graph(n);

    // construct the graph
    const int strLen = wordList[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int diffCount = 0;
        string &a = wordList[i];
        string &b = wordList[j];
        for (int k = 0; k < strLen; k++) {
          if (a[k] != b[k])
            diffCount++;
          if (diffCount > 1)
            break;
        }
        if (diffCount == 1) {
          graph[i].edges.push_back(j);
          graph[j].edges.push_back(i);
        }
      }
    }

    // compute path to end node
    vector<int> distance(n, numeric_limits<int>::max());
    int beginId = wordToId[beginWord];
    int endId = wordToId[endWord];

    distance[beginId] = 0;
    queue<int> q;
    q.push(beginId);
    while (!q.empty()) {
      int id = q.front();
      q.pop();
      if (id == endId)
        break;
      int dist = distance[id] + 1;
      for (int nextId : graph[id].edges) {
        if (dist <= distance[nextId]) {
          if (dist < distance[nextId]) {
            distance[nextId] = dist;
            q.push(nextId);
          }
          graph[nextId].backTraceEdges.push_back(id);
        }
      }
    }

    if (distance[endId] == numeric_limits<int>::max())
      return {};

    // retrieve the path
    auto getPath = [&](auto &&self, int finalId) -> vector<vector<int>> {
      if (finalId == beginId)
        return {{finalId}};
      vector<vector<int>> all;
      for (int backTraceId : graph[finalId].backTraceEdges) {
        vector<vector<int>> prev = self(self, backTraceId);
        for (auto arr : prev) {
          arr.push_back(finalId);
          all.emplace_back(arr);
        }
      }
      return all;
    };

    // convert path to strings
    vector<vector<int>> idAns = getPath(getPath, endId);
    vector<vector<string>> ans;
    for (auto &idPath : idAns) {
      vector<string> strAns;
      for (int id : idPath) {
        strAns.push_back(wordList[id]);
      }
      ans.emplace_back(strAns);
    }

    return ans;
  }
};

int main() {
  Solution sol;
  // vector<string> arr = {"hot", "dot", "dog", "lot", "log", "cog"};
  // print_matrix(sol.findLadders("hit", "cog", arr));
  vector<string> arr = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
  print_matrix(sol.findLadders("red", "tax", arr));
  return 0;
}
