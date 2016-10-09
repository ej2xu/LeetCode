class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    sort(nums.begin(), nums.end());
    return combSum(nums, sum / 2, 0);
  }

  bool combSum(vector<int>& cand, int target, int begin) {
    if (!target)
      return true;
    for (int i = begin; i < cand.size() && cand[i] <= target; i++)
      if (combSum(cand, target-cand[i], i+1)) return true;
    return false;
  }
};
