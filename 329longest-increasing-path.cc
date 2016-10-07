class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& mat) {
    m = mat.size();
    if (!m) return 0;
    n = mat[0].size();
    mem = vector<vector<int>>(m, vector<int>(n, 0));
    this->mat = mat;
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!mem[i][j])
          res = max(res, dfs(i, j));
    return res;
  }
private:
  int m, n;
  vector<vector<int>> mem, mat;
  int dfs(int i, int j) {
    if (mem[i][j])
      return mem[i][j];
    int res = 0, cur = mat[i][j];
    if (i && mat[i-1][j] > cur) res = max(res, dfs(i-1, j));
    if (j && mat[i][j-1] > cur) res = max(res, dfs(i, j-1));
    if (i < m-1 && mat[i+1][j] > cur) res = max(res, dfs(i+1, j));
    if (j < n-1 && mat[i][j+1] > cur) res = max(res, dfs(i, j+1));
    return mem[i][j] = res+1;
  }
};
