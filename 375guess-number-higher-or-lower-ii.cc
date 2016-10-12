class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, INT_MAX));
    for (int i = 1; i < n+2; i++)
      dp[i][i-1] = dp[i][i] = 0;
    for (int i = n-1; i >= 1; i--)
      for (int j = i+1; j <= n; j++)
        for (int k = i; k <= j; k++)
          dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j])+k);
    return dp[1][n];
  }
};

// http://artofproblemsolving.com/community/c296841h1273742
class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int j = 2; j <= n; j++) {
      deque<pair<int, int>> q;
      for (int k = j-1, i = j; --i; ) {
        while (a[i][k-1] > a[k+1][j]) k--;
        while (q.size() && k < q.front().second) q.pop_front();
        long t = a[i+1][j]+i;
        while (q.size() && q.back().first >= t) q.pop_back();
        q.emplace_back(t, i);
        a[i][j] = min(q.front().first, a[i][k]+k+1);
      }
    }
    return a[1][n];
  }
};
