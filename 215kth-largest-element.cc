class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    auto p = nums.end() - k;
    nth_element(nums.begin(), p, nums.end());
    return *p;
  }
};

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1;
    k--;
    while (l<r) {
      int q = partition(nums, l, r);
      if (q < k)
        l = q+1;
      else if (q > k)
        r = q-1;
      else break;
    }
    return nums[k];
  }
private:
  int partition(vector<int>& a, int l, int r) {
    int x = a[r], i = l;
    for (int j = l; j < r; j++)
      if (a[j] > x)
        swap(a[j], a[i++]);
    swap(a[r], a[i]);
    return i;
  }
};
