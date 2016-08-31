class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      return findPeakRec(nums, 0, nums.size());
    }

    int findPeakRec(vector<int>& a, int l, int h) {
      int m = (l + h) / 2;
      if (a[m] < a[m-1])
        return findPeakRec(a, l, m);
      if (a[m] < a[m+1])
        return findPeakRec(a, m, h);
      return m;
    }
};
