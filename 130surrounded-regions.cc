class Solution {
public:
  void solve(vector<vector<char>>& b) {
    int m = b.size();
    if (!m) return;
    int n = b[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      if (b[i][0] == 'O') {
        q.push({i, 0});
        b[i][0] = 'Y';
      }
      if (b[i][n-1] == 'O') {
        q.push({i, n-1});
        b[i][n-1] = 'Y';
      }
    }
    for (int j = 1; j < n-1; j++) {
      if (b[0][j] == 'O') {
        q.push({0, j});
        b[0][j] = 'Y';
      }
      if (b[m-1][j] == 'O') {
        q.push({m-1, j});
        b[m-1][j] = 'Y';
      }
    }
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int xx = u.first+dx[i], yy = u.second+dy[i];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && b[xx][yy] == 'O') {
          q.push({xx, yy});
          b[xx][yy] = 'Y';
        }
      }
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        b[i][j] = b[i][j] == 'Y' ? 'O' : 'X';
  }
};
