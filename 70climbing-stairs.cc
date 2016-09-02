class Solution {
public:
    int climbStairs(int n) {
      int dp[n+1], f;
      dp[1] = dp[0] = 1;
      for (int k = 2; k <= n; k++)
        dp[k] = dp[k-1]+dp[k-2];
      return dp[n];
    }
};

//MaskRay's Solution
class Solution {
public:
  int climbStairs(int n) {
    int a = 1, b = 1, t;
    while (n--)
      t = a+b, a = b, b = t;
    return a;
  }
};
