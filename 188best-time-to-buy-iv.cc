class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (!k) return 0;
    vector<int> b(k, INT_MIN), s(k, 0);
    for (int p : prices) {
      b[0] = max(b[0], -p);
      s[0] = max(s[0], b[0]+p);
      for (int i = 1; i < k; i++) {
        b[i] = max(b[i], s[i-1]-p);
        s[i] = max(s[i], b[i]+p);
      }
    }
    return s[k-1];
  }
};
