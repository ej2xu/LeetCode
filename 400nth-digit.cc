class Solution {
public:
  int findNthDigit(int n) {
    int len = 1, base = 1;
    while (n > 9L * base * len) {
      n -= 9 * base * len;
      len++;
      base *= 10;
    }
    int start = (n-1)/len + base, remain = (n-1)%len;
    while (remain--)
      base /= 10;
    return (start/base)%10;
  }
};
