class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int b = INT_MIN, prev_s = 0, s = 0;
      for (int p : prices) {
        prev_b = b;
        b = max(prev_s-p, b);
        prev_s = s;
        s = max(prev_b+p, s);
      }
      return s;
    }
};
