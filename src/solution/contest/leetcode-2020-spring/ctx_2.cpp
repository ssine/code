#include "leetcode.h"
#include "utils.h"

class Solution {
  vector<string> maze;
  int n, m;
  pair<int, int> start, end;
  vector<pair<int, int>> M, O;
  map<pair<int, int>, int> Midx, Oidx;
  vector<vector<int>> MODis;

  void fillDistance() {
    for (const auto& opos : O) {
      vector<vector<int>> d(n, vector<int>(m, numeric_limits<int>::max()));
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      queue<pair<int, int>> q;
      d[opos.first][opos.second] = 0;
      q.push(opos);
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        vector<pair<int, int>> childs{{cur.first + 1, cur.second},
                                      {cur.first - 1, cur.second},
                                      {cur.first, cur.second + 1},
                                      {cur.first, cur.second - 1}};
        for (auto& pos : childs) {
          if (pos.first >= 0 && pos.first < n && pos.second >= 0 &&
              pos.second < n && !vis[pos.first][pos.second]) {
            vis[pos.first][pos.second] = true;
            if (maze[pos.first][pos.second] == '#')
              continue;
            q.push(pos);
            d[pos.first][pos.second] =
                min(d[pos.first][pos.second], d[cur.first][cur.second] + 1);
            if (maze[pos.first][pos.second] == 'M' ||
                maze[pos.first][pos.second] == 'S') {
              MODis[Midx[pos]][Oidx[opos]] = d[pos.first][pos.second];
            }
          }
        }
      }
    }
  }

 public:
  int minimalSteps(vector<string>& maze_) {
    maze = maze_;
    n = maze.size();
    m = maze[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        auto p = make_pair(i, j);

        if (maze[i][j] == 'S')
          start = p;
        else if (maze[i][j] == 'T')
          end = p;

        if (maze[i][j] == 'M' || maze[i][j] == 'S') {
          M.push_back(p);
          Midx[p] = M.size() - 1;
        } else if (maze[i][j] == 'O' || maze[i][j] == 'T') {
          O.push_back(p);
          Oidx[p] = O.size() - 1;
        }
      }
    }
    vector<vector<int>> modis(M.size(), vector<int>(O.size()));
    MODis = modis;
    fillDistance();
    print_matrix(MODis);
    cout << "start idx: " << Midx[start] << endl;
    cout << "end idx: " << Oidx[end] << endl;
    vector<vector<int>> dis(
        M.size() + 2, vector<int>(M.size() + 2, numeric_limits<int>::max()));
    for (int i = 0; i < M.size() + 2; i++) {
      for (int j = 0; j < i; j++) {
        if (i == Midx[start] && j == Oidx[end]) continue;
        if (i == M.size() + 1)
        for (int k = 0; k < O.size(); k++) {
          if (k == Oidx[end]) continue;
          dis[i][j] = min(dis[i][j], MODis[i][j]);
        }
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<string> arr = {"S#O", "M..", "M.T"};
  print_vector(arr);
  cout << sol.minimalSteps(arr) << endl;
  return 0;
}
