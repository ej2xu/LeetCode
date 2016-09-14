class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& a, int target) {
    vector<vector<int>> r;
    int n = a.size(), h = 0;
    if (n<4) return r;
    sort(a.begin(), a.end());
    while (true) {
      int i = h+1;
      while (true) {
        int j = i+1, k = n-1, s = target-a[i]-a[h];
        while (j < k) {
          if (a[j]+a[k] < s) j++;
          else if (a[j]+a[k] > s) k--;
          else {
            r.push_back(vector<int>{a[h], a[i], a[j], a[k]});
            while (a[j]==a[++j] && j<k);
            k--;
          }
        }
        while (a[i]==a[++i] && i<j);
        if (i==j) break;
      }
      while (a[h]==a[++h] && h<i-1);
      if (h==i-1) break;
    }
    return r;
  }
};

//early proning
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};
