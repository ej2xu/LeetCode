enum ocean {N, P, A};
struct cell {
  int x, y;
  ocean o;
  cell(int _x, int _y, ocean _o) : x(_x), y(_y), o(_o) {}
};

class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& mat) {
    vector<pair<int, int>> res;
    if (!mat.size() || !mat[0].size()) return res;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> visit(m, vector<int>(n, 0));
    queue<cell> q;
    for (int i = 0; i < m; ++i) {
      q.emplace(i, 0, P);
      q.emplace(i, n-1, A);
    }
    for (int j = 0; j < n; ++j) {
      q.emplace(0, j, P);
      q.emplace(m-1, j, A);
    }
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      if (visit[u.x][u.y] & u.o) continue;
      if ((visit[u.x][u.y] |= u.o) == 3)
        res.push_back({u.x, u.y});
      int cur = mat[u.x][u.y];
      for (int i = 0; i < 4; ++i) {
          int xx = u.x + dx[i], yy = u.y + dy[i];
          if (xx >= 0 && xx < m && yy >= 0 && yy < n && mat[xx][yy] >= cur && !(visit[xx][yy] & u.o))
            q.emplace(xx, yy, u.o);
      }
    }
    return res;
  }
};
