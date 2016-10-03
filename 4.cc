class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    if (!nums.size()) return 0;
    long sum = 0;
    for (int num: nums)
      sum += num;
    long l = sum / m, h = sum;
    while (l < h) {
      long mid = l + (h-l)/2;
      bool flag = check(nums, mid, m);
      if (flag)
        l = mid+1;
      else
        h = mid;
    }
    return h;
  }
private:
  int check(vector<int>& nums, long mid, long m) {
    int count = 1;
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > mid) return true;
        if (sum+nums[i] <= mid)
          sum += nums[i];
        else {
          count++;
          sum = nums[i];
        }
    }
    return count > m;
  }
};
