class Solution {
public:
    int countDigitOne(int n) {
      if (n <= 0) return 0;
      int result = 0, dec = 1;
      while (dec <= n) {
        result = result * ((n/dec)%10) + dec;
        dec *= 10;
      }
      return result;
    }
};
