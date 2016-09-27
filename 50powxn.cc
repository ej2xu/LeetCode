class Solution {
public:
  double myPow(double x, int n) {
    double res = 1.0;
    if (n < 0) {
      x = 1.0/x;
      if (n == INT_MIN) {
        res = x;
        n++;
      }
      n = -n;
    }
    for (; n; n >>= 1, x *= x)
      if (n & 1)
        res *= x;
    return res;
  }
};
