class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> count(n, 1);
    vector<int> parent(n, 0);
    int max = 0, index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i-1; j >= 0; j--)
        if (!(nums[i]%nums[j]) && count[j]+1 > count[i]) {
          count[i] = count[j]+1;
          parent[i] = j;
        }
      if (count[i] > max) {
        max = count[i];
        index = i;
      }
    }
    vector<int> res;
    while (max--) {
      res.push_back(nums[index]);
      index = parent[index];
    }
    return res;
  }
};

//MaskRay's Solution

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    unordered_map<int, pair<int, int>> dp;
    sort(nums.begin(), nums.end());
    for (int x: nums) {
      dp[x] = {1, 0};
      for (int i = 1; i <= x/i; i++)
        if (x%i == 0) {
          if (dp.count(i) && dp[i].first + 1 > dp[x].first && i < x)
            dp[x] = {dp[i].first + 1, i};
          if (dp.count(x/i) && dp[x/i].first + 1 > dp[x].first && i > 1)
            dp[x] = {dp[x/i].first + 1, x/i};
        }
    }
    int x = 0, s = 0;
    for (auto& it: dp)
      if (it.second.first > s)
        s = it.second.first, x = it.first;
    vector<int> r;
    for (; dp.count(x); x = dp[x].second)
      r.push_back(x);
    return r;
  }
};
