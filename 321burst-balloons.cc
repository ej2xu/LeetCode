class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for (int i = n; i >= 1; i--)
      for (int j = i; j <= n; j++)
        for (int k = i; k <= j; k++)
          dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
    return dp[1][n];
  }
};

// topological order based on length k (by dietpepsi)
int maxCoinsDP(vector<int> &iNums) {
    int nums[iNums.size() + 2];
    int n = 1;
    for (int x : iNums) if (x > 0) nums[n++] = x;
    nums[0] = nums[n++] = 1;


    int dp[n][n] = {};
    for (int k = 2; k < n; ++k) {
        for (int left = 0; left < n - k; ++left)
            int right = left + k;
            for (int i = left + 1; i < right; ++i)
                dp[left][right] = max(dp[left][right],
                     nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
        }

    return dp[0][n - 1];
}
