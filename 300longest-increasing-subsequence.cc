class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 1;
    if (!n) return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++)
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j]);
      dp[i]++;
      res = max(res, dp[i]);
    }
    return res;
  }
};

// https://discuss.leetcode.com/topic/28738/java-python-binary-search-o-nlogn-time-with-explanation/13
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int size = 0;
    for (int x: nums) {
      int l = 0, h = size;
      while (l != h) {
        int m = l + h >> 1;
        if (nums[m] < x)
          l = m+1;
        else h = m;
      }
      nums[l] = x;
      if (l == size)
        size++;
    }
    return size;
  }
};

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
