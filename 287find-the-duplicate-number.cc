class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[slow];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return fast;
  }
};

//binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size()-1;
        while (l < r) {
            int m = l+r>>1;
            int cnt = notGreaterThan(nums, m);
            if (cnt <= m) l = m + 1;
            else r = m;
        }
        return l;
    }
private:
    int notGreaterThan(vector<int>& nums, int target) {
        int cnt = 0;
        for (int num : nums)
            if (num <= target)
                cnt++;
        return cnt;
    }
};

// MaskRay's bit manipulation
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int r = 0;
    for (int b = 1; b < nums.size(); b <<= 1) {
      int c = 0;
      for (int i = 0; i < nums.size(); i++)
        c += !!(nums[i]&b)-!!(i&b);
      if (c)
        r |= b;
    }
    return r;
  }
};
