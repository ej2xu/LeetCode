//newton's method
// Hacker's Delight (2nd) 11.1.1
// 46340 = floor(sqrt(INT_MAX))
class Solution {
public:
  bool isPerfectSquare(int num) {
    int x = 46340, y;
    while ((y = (x+num/x)>>1) < x)
      x = y;
    return x*x == num;
  }
};

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num > 2147395600) return false;
    int i = 2;
    while (num > 1) {
      while (num % (i*i) && i*i <= num) i++;
      if (i*i > num) break;
      num /= i*i;
    }
    return num == 1;
  }
};
