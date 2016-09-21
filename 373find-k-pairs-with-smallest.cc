class cmp {
  public:
    bool operator() (const tuple<int, int, int> &lhs, const tuple<int, int, int> &rhs) const {
      return get<0>(lhs) > get<0>(rhs);
    }
};

class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    int m = nums1.size(), n = nums2.size();
    if (!m || !n)
      return res;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> mHeap;
    tuple<int, int, int> cur;
    mHeap.push(make_tuple(nums1[0]+nums2[0], 0, 0));
    while (k-- && !mHeap.empty()) {
      cur = mHeap.top();
      mHeap.pop();
      int i = get<1>(cur);
      int j = get<2>(cur);
      res.emplace_back(nums1[i], nums2[j]);
      if (!i && j+1 < n)
        mHeap.push(make_tuple(nums1[i]+nums2[j+1], i, j+1));
      if (++i < m)
        mHeap.push(make_tuple(nums1[i]+nums2[j], i, j));
    }
    return res;
  }
};

// MaskRay's Solution
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    typedef pair<int, int> pii;
    vector<pii> r;
    if (nums1.empty() || nums2.empty())
      return r;
    auto cmp = [&](const pii& x, const pii& y) {
      return nums1[x.first]+nums2[x.second] > nums1[y.first]+nums2[y.second];
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0);
    while (k-- && pq.size()) {
      pii x = pq.top();
      pq.pop();
      r.emplace_back(nums1[x.first], nums2[x.second]);
      if (x.first+1 < nums1.size())
        pq.emplace(x.first+1, x.second);
      if (! x.first && x.second+1 < nums2.size())
        pq.emplace(x.first, x.second+1);
    }
    return r;
  }
};
