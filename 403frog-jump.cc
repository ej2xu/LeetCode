class Solution {
public:
  bool canCross(vector<int>& stones) {
    if (stones[1] != 1) return false;
    return canCross(stones, 1, 1);
  }
  // pos < 1100
  bool canCross(vector<int>& stones, int pos, int k) {
    int key = pos | k << 11;
    if (mem.count(key))
      return mem[key];
    int cur = stones[pos];
    for (int i = pos+1; i < stones.size(); i++) {
      int nextk = stones[i]-cur;
      if (nextk < k-1) continue;
      if (nextk > k+1)
        return mem[key] = false;
      if (canCross(stones, i, nextk))
        return mem[key] = true;
    }
    return mem[key] = (cur == stones.back());
  }
private:
  unordered_map<int, bool> mem;
};

// MaskRay's Solution
class Solution {
public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<unordered_set<int>> dp(n);
    dp[0].insert(0);
    for (int i = 1; i < n; i++)
      for (int j = i-1; j >= 0 && stones[j]+j+1 >= stones[i]; j--) {
        int t = stones[i]-stones[j];
        if (dp[j].count(t-1) || dp[j].count(t) || dp[j].count(t+1))
          dp[i].insert(t);
      }
    return dp.back().size();
  }
};
