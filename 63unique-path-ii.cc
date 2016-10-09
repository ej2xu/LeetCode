class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n  = grid[0].size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j])
          dp[j] = 0;
        else if (j)
          dp[j] += dp[j-1];
    return dp[n-1];
  }
};

// in case of no solution, fast break
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> cur(m, 0);
    for (int i = 0; i < m; i++)
      if (!obstacleGrid[i][0])
          cur[i] = 1;
      else break;
    for (int j = 1; j < n; j++) {
        bool flag = false;
        if (obstacleGrid[0][j])
            cur[0] = 0;
        else if (cur[0])
          flag = true;
        for (int i = 1; i < m; i++)
          if (obstacleGrid[i][j])
            cur[i] = 0;
          else {
            cur[i] += cur[i - 1];
            if (cur[i]) flag = true;
          }
        if (!flag) return 0;
    }
    return cur[m - 1];
  }
};
