class Solution {
public:
  int uniquePaths(int m, int n) {
    if (n > m) swap(m, n);
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        dp[j] += dp[j-1];
    return dp[n-1];
  }
};

// {m+n-2 \choose m-1}
class Solution {
  public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int k = min(m, n) - 1;
        long res = 1;
        N -= k;
        for (int i = 1; i <= k; i++) {
            res *= (N + i);
            res /= i;
        }
        return res;
    }
};

// MaskRay's solution
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int uniquePaths(int m, int n) {
    const int TEN = 10000000;
    int s = 1;
    m--;
    n--;
    n += m;
    vector<int> a(max(n, 1));
    a[0] = 1;
    REP(i, m) {
      int c = 0;
      REP(j, s) {
        a[j] = a[j]*(n-i)+c;
        c = a[j]/TEN;
        a[j] %= TEN;
      }
      if (c) {
        a[s++] = c;
        c = 0;
      }
      ROF(j, 0, s) {
        a[j] = c*TEN+a[j];
        c = a[j]%(i+1);
        a[j] /= i+1;
      }
      while (! a[s-1])
        s--;
    }
    if (s > 1)
      a[0] += a[1]*TEN;
    return a[0];
  }
};
