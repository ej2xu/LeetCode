class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (s.empty() || p.empty()) return res;
    vector<int> h(128, 0);
    for (char c: p)
      h[c]++;
    int l = 0, r = 0, count = p.size();
    while (r < s.size()) {
      if (h[s[r++]]-- >= 1)
        count--;
      if (!count)
        res.push_back(l);
      if (r-l == p.size() && h[s[l++]]++ >= 0)
        count++;
    }
    return res;
  }
};
