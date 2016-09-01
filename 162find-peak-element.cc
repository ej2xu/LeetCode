class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      return findPeakRec(nums, 0, nums.size()-1);
    }

    int findPeakRec(vector<int>& a, int l, int h) {
      if (l == h)
        return l;
      int m = (l+h)/2;
      if (m > 0 && a[m] < a[m-1])
        return findPeakRec(a, l, m-1);
      if (a[m] < a[m+1])
        return findPeakRec(a, m+1, h);
      return m;
    }
};
