class Solution {
public:
    int mySqrt(int a) {
      if (!a) return 0;
      long x = 1, y;
      while (x*x < a)
        x <<= 1;
      while ((y = (x+a/x)>>1) < x)
        x = y;
      return x;
    }
};
// long r = x;
// while (r*r > x)
//     r = (r + x/r) / 2;
// return r;

// Hacker's Delight (2nd) 11.1.1
// 46340 = floor(sqrt(INT_MAX))
class Solution {
public:
  int sqrt(int x) {
    if (x <= 1) return x;
    int y = 46340, z;
    while ((z = (y+x/y)>>1) < y)
      y = z;
    return y;
  }
};
