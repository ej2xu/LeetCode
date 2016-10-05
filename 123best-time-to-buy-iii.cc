class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int b = INT_MIN, s = 0, bb = INT_MIN, ss = 0;
    for (int p : prices) {
      b = max(b, -p);
      s = max(s, b+p);
      bb = max(bb, s-p);
      ss = max(ss, bb+p);
    }
    return ss;
  }
};
