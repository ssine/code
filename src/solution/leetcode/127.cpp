#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, int> wordToId;
    wordList.push_back(beginWord);
    const int n = wordList.size();
    for (int i = 0; i < n; i++)
      wordToId[wordList[i]] = i;
    if (wordToId.count(endWord) == 0)
      return 0;

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
      return 0;

    return distance[endId] + 1;
  }
};

int main() {
  Solution sol;
  vector<string> arr = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << sol.ladderLength("hit", "cog", arr) << endl;
  // vector<string> arr = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
  // cout << sol.findLadders("red", "tax", arr) << endl;
  return 0;
}
