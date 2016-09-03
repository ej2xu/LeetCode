class Solution {
public:
    int maxProduct(vector<int>& a) {
      int prod = a[0], mi = a[0], ma = a[0];
      for (int i = 1; i < a.size(); i++) {
        int x = a[i], s = mi*x, t = ma*x;
        mi = min(x, min(s,t));
        ma = max(x, max(s,t));
        prod = max(prod, ma);
      }
      return prod;
    }
};
