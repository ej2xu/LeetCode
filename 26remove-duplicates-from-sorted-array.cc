class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (!nums.size())
        return 0;
      int i = 1, j = 0;
      for (; i<nums.size();i++)
        if (nums[i] != nums[j])
          nums[++j] = nums[i];
      return j + 1;
    }
};

//MaskRay's Solution
class Solution {
public:
  int removeDuplicates(vector<int> &a) {
    int j = 0;
    for (auto x: a)
      if (!j || a[j-1] != x)
        a[j++] = x;
    return j;
  }
};
