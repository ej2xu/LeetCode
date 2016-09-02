class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
      vector<int> c(m+n);
      int i = 0, j = 0;
      while(i < m && j < n)
        if (a[i] < b[j])
          c[i+j] = a[i++];
        else
          c[i+j] = b[j++];
      while (i < m)
        c[i+j] = a[i++];
      while (j < n)
        c[i+j] = b[j++];
      swap(a,c);
    }
};

//deck's solution of in place merge
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
