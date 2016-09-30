class Solution {
public:
  struct cell {
    int x, y, h;
    cell(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
  };
  struct cmp {
    bool operator() (const cell &a, const cell &b) {
      return a.h > b.h;
    }
  };
  int trapRainWater(vector<vector<int> > &heights) {
    if (heights.empty() || heights[0].empty()) return 0;
    int n = heights.size(), m = heights[0].size();
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    priority_queue<cell, vector<cell>, cmp> heap;
    for (int i = 1; i < n-1; ++i) {
      heap.emplace(i, 0, heights[i][0]);
      heap.emplace(i, m - 1, heights[i][m-1]);
      visit[i][0] = visit[i][m-1] = true;
    }
    for (int j = 1; j < m-1; ++j) {
        heap.emplace(0, j, heights[0][j]);
        heap.emplace(n - 1, j, heights[n-1][j]);
        visit[0][j] = visit[n-1][j] = true;
    }
    visit[0][0] = visit[n-1][0] = visit[n-1][m-1] = visit[0][m-1] = true;
    int res = 0;
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!heap.empty()) {
        auto u = heap.top();
        heap.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = u.x + dx[i], yy = u.y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visit[xx][yy]) {
                res += max(0, u.h - heights[xx][yy]);
                heap.emplace(xx, yy, max(u.h, heights[xx][yy]));
                visit[xx][yy] = true;
            }
        }
    }
    return res;
  }
};
