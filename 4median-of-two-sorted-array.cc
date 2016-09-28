class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size(), k = m+n-1 >> 1;
    if (m+n & 1) return getkth(nums1, nums2, k);
    return 0.5*getkth(nums1, nums2, k) + 0.5*getkth(nums1, nums2, k+1);
  }
private:
  int getkth(vector<int>& a, vector<int>& b, int k) {  // 0 index
    int m = a.size(), n = b.size(), i = 0, j = 0;
    while (k) {
      int p = k-1>>1;
      if (i+p >= m || j+p < n && a[i+p] > b[j+p])
        j += p+1;
      else
        i += p+1;
      k -= p+1;
    }
    return i >= m || j < n && a[i] > b[j] ? b[j] : a[i];
  }
};
// change the last two lines of getkth to unify findMedianSortedArrays to one piece. But getkth is a useful function worth seperating out.
// int s = j >= n || i < m && a[i] < b[j] ? a[i++] : b[j++];
// return m+n & 1 ? s : (j >= n || i < m && a[i] < b[j] ? s+a[i] : s+b[j]) * 0.5;

// another way of writing getkth
int getkth(vector<int>& a, vector<int>& b, int k) {  // 0 index
  int m = a.size(), n = b.size(), i = 0, j = 0;
  while (m && n && k) {
    int p = k-1>>1, ii = min(m-1, p), jj = min(n-1, p);
    if (a[i+ii] > b[j+jj])
      j += jj+1, n -= jj+1, k -= jj+1;
    else
      i += ii+1, m -= ii+1, k -= ii+1;
  }
  if (!m) return b[j+k];
  if (!n) return a[i+k];
  return min(a[i], b[j]);
}


class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    bool odd = m+n & 1;
    int k = m+n-1>>1;
    if (!m)
      return odd ? nums2[k] : 0.5*nums2[k] + 0.5*nums2[k+1];
    if (nums1[0] >= nums2[k]) {
      if (odd) return nums2[k];
      return 0.5*nums2[k] + 0.5*(k==n-1 || nums2[k+1]>nums1[0] ? nums1[0] : nums2[k+1]);
    }
    if (k >= m) {
      if (nums2[k-m] >= nums1[m-1])
        return odd ? nums2[k-m] : 0.5*nums2[k-m] + 0.5*nums2[k-m+1];
      else if (nums1[m-1] <= nums2[k-m+1])
        return odd ? nums1[m-1] : 0.5*nums1[m-1] + 0.5*nums2[k-m+1];
    } else if (nums1[m-1] <= nums2[0])
      return odd ? nums1[m-1] : 0.5*nums1[m-1] + 0.5*nums2[0];

    int l = 0, h = m-1;
    while (l <= h) {
      int i = l+h >> 1, j = k-i-1;
      if (nums1[i] < nums2[j]) {
        if (nums1[i+1] >= nums2[j])
          return odd ? nums2[j] : 0.5*nums2[j] + 0.5*min(nums1[i+1], nums2[j+1]);
        l = i+1;
      } else {
        if (nums2[j+1] >= nums1[i])
          return odd ? nums1[i] : 0.5*nums1[i] + 0.5*min(nums2[j+1], nums1[i+1]);
        h = i-1;
      }
    }
    return -1;
  }
};

class Solution {
  public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    if (!m) return 0.5*nums2[(n-1)/2] + 0.5 * nums2[n/2];

    int lo = 0, hi = m * 2;
    while (lo <= hi) {
      int mid1 = (lo + hi) / 2;
      int mid2 = m + n - mid1;

      double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];   // Get L1, R1, L2, R2 respectively
      double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
      double R1 = (mid1 == m * 2) ? INT_MAX : nums1[(mid1)/2];
      double R2 = (mid2 == n * 2) ? INT_MAX : nums2[(mid2)/2];

      if (L2 > R1) lo = mid1 + 1;
      else if (L1 > R2) hi = mid1 - 1;
      else return (max(L1,L2) + min(R1, R2)) / 2;      // Otherwise, that's the right cut.
    }
    return -1;
  }
};

//most voted answer
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int i, j, imin = 0, imax = m, half = (m + n + 1) / 2;
        while (imin <= imax) {
            i = (imin & imax) + ((imin ^ imax) >> 1);
            j = half - i;
            if (i > 0 && j < n && nums1[i - 1] > nums2[j]) imax = i - 1;
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) imin = i + 1;
            else break;
        }
        int num1;
        if (!i) num1 = nums2[j - 1];
        else if (!j) num1 = nums1[i - 1];
        else num1 = max(nums1[i - 1], nums2[j - 1]);
        if ((m + n) & 1) return num1;
        int num2;
        if (i == m) num2 = nums2[j];
        else if (j == n) num2 = nums1[i];
        else num2 = min(nums1[i], nums2[j]);
        return (num1 + num2) / 2.0;
    }
};
