class Solution {
public:
  int divide(int a, int b) {
    if (a == INT_MIN) {
      if (b == -1) return INT_MAX;
      if (b == 1) return INT_MIN;
      return (b&1) == 1 ? divide(a|1, b) : divide(a>>1, b>>1);
    }
    if (b == INT_MIN) return 0;
    bool neg = false;
    if (a < 0)
      a = -a, neg = !neg;
    if (b < 0)
      b = -b, neg = !neg;
    int quo = 0, count = 0;
    while (!(b & 1<<31) && b <= a) {
      count++;
      b <<= 1;
    }
    unsigned int bb = b;
    while (count--) {
      bb >>= 1;
      quo <<= 1;
      if (a >= bb) {
        a -= bb;
        quo |= 1;
      }
    }
    return neg ? -quo : quo;
  }
};

//cast to long
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};
