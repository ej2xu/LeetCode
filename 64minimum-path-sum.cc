class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
      int m = a.size(), n = a[0].size(), i = 1, j = 1;
      for (; j < n; j++)
        a[0][j] += a[0][j-1];
      for (; i < m; i++)
        a[i][0] += a[i-1][0];
      for (i = 1; i < m; i++)
        for (j = 1; j < n; j++)
          a[i][j] += max(a[i-1][j], a[i][j-1]);
      return a[m-1][n-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
