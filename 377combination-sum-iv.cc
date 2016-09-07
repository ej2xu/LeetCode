class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      int c[target+1] = {0};
      c[0] = 1;
      for (int sum = 1; sum <= target; sum++)
        for (int i = 0; i < nums.size(); i++)
          if (nums[i] <= sum)
            c[sum] += c[sum-nums[i]];
      return c[target];
    }
};

//MaskRay's bottom up Solution
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> a(target+1, 0);
    a[0] = 1;
    for (int i = 0; i < target; i++)
      for (int x: nums)
        if (i+x <= target)
          a[i+x] += a[i];
    return a[target];
  }
};
