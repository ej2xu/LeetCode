class Solution {
public:
    int rob(vector<int>& nums) {
      int size = nums.size();
      if (!size) return 0;
      int numsum[size];
      numsum[0] = nums[0];
      numsum[1] = max(nums[0], nums[1]);
      for (int i = 2; i < size; i++)
        numsum[i] = max(nums[i]+numsum[i-2], numsum[i-1]);
      return numsum[size-1];
    }
};

class Solution {
public:
  int rob(vector<int> &a) {
    int pre = 0, cur = 0;
    for (auto n: a) {
      int tmp = max(pre+n, cur);
      pre = cur;
      cur = tmp;
    }
    return x;
  }
};
