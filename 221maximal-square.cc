class Solution {
public:
  int maximalSquare(vector<vector<char>>& mat) {
    if (mat.empty()) return 0;
    int m = mat.size(), n = mat[0].size();
    vector<int> dp(n, 0);
    int ma = 0;
    for (int i = 0; i < n; i++) {
      dp[i] = mat[0][i] - '0';
      ma = max(ma, dp[i]);
    }
    for (int i = 1; i < m; i++) {
      int pre = dp[0];
      dp[0] = mat[i][0] - '0';
      ma = max(ma, dp[0]);
      for (int j = 1; j < n; j++) {
        int tmp = dp[j];
        if (mat[i][j] == '1') {
          dp[j] = 1+min(min(dp[j], dp[j-1]), pre);
          ma = max(ma, dp[j]);
        } else
          dp[j] = 0;
        pre = tmp;
      }
    }
    return ma*ma;
  }
};
