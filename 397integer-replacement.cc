class Solution {
public:
  int integerReplacement(int n) {
    int res = 0;
    unsigned m = n;
    while (m > 3) {
      if (!(m & 1))
        m >>= 1;
      else if (m & 2)
        m++;
      else
        m--;
      res++;
    }
    return res + m - 1;
  }
};
