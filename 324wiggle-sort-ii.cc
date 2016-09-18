#define A(i) nums[(2*i+1)%(n|1)]
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin() + n/2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr, i = 0, j = 0, k = n-1;
    while (j <= k)
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else j++;
  }
};
