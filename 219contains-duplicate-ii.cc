class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> occur;
    for (int i=0; i<nums.size(); i++) {
      if (occur.count(nums[i]) && i-occur[nums[i]] <= k)
        return true;
      occur[nums[i]] = i;
    }
    return false;
  }
};

//sliding window
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> occur;
    for (int i=0; i<nums.size(); i++) {
      if (i>k) occur.erase(nums[i-k-1]);
      if (!occur.insert(nums[i]).second)
        return true;
    }
    return false;
  }
};
