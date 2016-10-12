class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (!n || s[0] == '0') return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] != '0')
        dp[i+1] += dp[i];
      if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
        dp[i+1] += dp[i-1];
    }
    return dp[n];
  }
};

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (!n || s[0] == '0') return 0;
    int x = 1, y = 1;
    for (int i = 1; i < n; i++) {
      int xx = y;
      if (s[i] == '0')
        y = 0;
      if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
        y += x;
      x = xx;
    }
    return y;
  }
};
