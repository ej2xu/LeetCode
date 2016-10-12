class Solution {
public:
  int minDistance(string w1, string w2) {
    int m = w1.size(), n = w2.size();
    if (n > m) {
      swap(w1, w2);
      swap(m, n);
    }
    vector<vector<int>> dp(2, vector<int>(n+1));
    iota(dp[0].begin(), dp[0].end(), 0);
    for (int i = 0; i < m; i++) {
      dp[i+1&1][0] = i+1;
      for (int j = 0; j < n; j++)
        dp[i+1&1][j+1] = w1[i]==w2[j] ? dp[i&1][j] : 1+min(dp[i&1][j], min(dp[i+1&1][j], dp[i&1][j+1]));
    }
    return dp[m&1][n];
  }
};

// MaskRay's solution: further space saving

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minDistance(string a, string b) {
    if (a.size() < b.size())
      swap(a, b);
    vector<int> d(b.size()+1);
    iota(d.begin(), d.end(), 0);
    REP(i, a.size()) {
      int ul = d[0];
      d[0] = i+1;
      REP(j, b.size()) {
        int t = d[j+1];
        d[j+1] = a[i] == b[j] ? ul : min(ul, min(d[j], d[j+1])) + 1;
        ul = t;
      }
    }
    return d.back();
  }
};
