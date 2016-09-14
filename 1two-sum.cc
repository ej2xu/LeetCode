class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> imap;
      for (int i=0;; i++) {
        auto it = imap.find(target-nums[i]);
        if (it != imap.end())
          return vector<int> {i, it->second};
        imap[nums[i]] = i;
      }
    }
};

//sort first
class Solution {
public:
    vector<int> twoSum(vector<int> &a, int s) {
      vector<int> r(a.size());
      iota(r.begin(), r.end(), 0);
      sort(r.begin(), r.end(), [&](int x, int y) { return a[x] < a[y]; });
      for (size_t i = 0, j = a.size()-1; i < j; i++) {
        while (j > i+1 && a[r[i]]+a[r[j]] > s) j--;
        if (a[r[i]]+a[r[j]] == s)
          return vector<int> {r[i], r[j]};
      }
      return r;
    }
};
