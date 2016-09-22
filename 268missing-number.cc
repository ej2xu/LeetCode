class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = (int)nums.size();
    return n*(n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
  }
};

class Solution {
public:
  int missingNumber(vector<int> &a) {
    int n = (int)a.size();
    for (int i = 0; i < n; ) {
      int j = a[i];
      if (i != j && j < n)
        swap(a[i], a[j]);
      else
        i++;
    }
    for (int i = 0; i < n; i++)
      if (a[i] != i)
        return i;
    return n;
  }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        for(int i=0; i<nums.size(); ++i)
            res ^=(i+1)^nums[i];
        return res;
    }
};

public int missingNumber(int[] nums) { //binary search
    Arrays.sort(nums);
    int left = 0, right = nums.length, mid= (left + right)/2;
    while(left<right){
        mid = (left + right)/2;
        if(nums[mid]>mid) right = mid;
        else left = mid+1;
    }
    return left;
}
