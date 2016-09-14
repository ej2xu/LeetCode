class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k<1 || t<0) return false;
    typedef long long ll;
    unordered_map<ll, ll> map;
    for (size_t i=0; i<nums.size(); i++) {
      if (i>k)
        map.erase((ll(nums[i-k-1])-INT_MIN)/(t+1LL));
      ll x = nums[i], r = (x-INT_MIN)/(t+1LL);
      if (map.count(r) || map.count(r-1) && x-map[r-1]<=t || map.count(r+1) && map[r+1]-x<=t)
        return true;
      map[r] = x;
    }
    return false;
  }
};

//solution using set(Red-black tree)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
   set<int> window; // set is ordered automatically
   for (int i = 0; i < nums.size(); i++) {
       if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
       // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
       auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t
       // x - nums[i] <= t ==> |x - nums[i]| <= t
       if (pos != window.end() && *pos - nums[i] <= t) return true;
       window.insert(nums[i]);
   }
   return false;
}
