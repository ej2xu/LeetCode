class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int i = 0;
      for (int num : nums)
          if (num)
              nums[i++] = num;
      fill(a.begin()+i, a.end(), 0);
    }
};
