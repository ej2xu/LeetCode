class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
      for (int j = 0; j < n; j++)
        if (coins[j]<=i)
          dp[i] = min(dp[i], 1+dp[i-coins[j]]);
    return dp[amount] <= amount ? dp[amount] : -1;
  }
};

// TLE
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(amount+1, vector<int>(n+1, 0));
    for (int i = 1; i <= amount; i++) {
      dp[i][0] = amount+1;
      for (int j = 1; j <= n; j++) {
        int cur = coins[j-1];
        dp[i][j] = cur<=i ? min(dp[i][j-1], 1+dp[i-cur][j]) : dp[i][j-1];
      }
    }
    return dp[amount][n]<=amount ? dp[amount][n] : -1;
  }
};

// variation
int coinChange(vector<int>& coins, int amount)
    vector<int> A(amount+1, amount+1);
    A[0] = 0;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            A[i] = min(A[i], A[i - coin] + 1);
        }
    }
    return A[amount] > amount ? -1 : A[amount];
}

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    for (int x: coins)
      for (int i = x; i <= amount; i++)
        if (dp[i-x] >= 0 && (dp[i] < 0 || dp[i-x]+1 < dp[i]))
          dp[i] = dp[i-x]+1;
    return dp[amount];
  }
};
