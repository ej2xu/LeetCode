class Solution {
public:
    int maxSubArray(vector<int>& a) {
      int maxendhere = a[0], maxsofar = maxendhere;
      for (int i = 1; i < a.size(); i++) {
        maxendhere = max(0, maxendhere) + a[i];
        maxsofar = max(maxendhere, maxsofar);
      }
      return maxsofar;
    }
};

//CLRS chapter 4.1 divide and conquer
class Solution {
public:
  int maxSubArray(vector<int>& a) {
    return findMaxSub(a, 0, a.size()-1);
  }
private:
  int findMaxSub(vector<int>& a, int low, int high) {
    if (high == low)
      return a[low];
    int mid = low + high >> 1;
    return max(max(findMaxSub(a, low, mid), findMaxSub(a, mid+1, high)), findMaxCrossing(a, low, mid, high));
  }

  int findMaxCrossing(vector<int>& a, int low, int mid, int high) {
    int leftS = INT_MIN, rightS = leftS, sum = 0;
    for (int i = mid; i >= low; i--) {
      sum += a[i];
      if (sum > leftS)
        leftS = sum;
    }
    sum = 0;
    for (int i = mid+1; i <= high; i++) {
      sum += a[i];
      if (sum > rightS)
        rightS = sum;
    }
    return leftS + rightS;
  }
};

//O(n) divide and conquer
class Solution {
public:
    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
        }
        else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            sum = sum1 + sum2;
        }
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int mx, lmx, rmx, sum;
        maxSubArray(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
        return mx;
    }
};
