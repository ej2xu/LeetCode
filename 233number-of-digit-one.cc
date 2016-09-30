class Solution {
public:
  int countDigitOne(int n) {
    int res = 0, nn = n;
    for (int m = 1; nn; nn /= 10, m *= 10) {
      int l = n/m, r = n%m;
      res += (l+8)/10*m + (l%10==1)*(r+1);
    }
    return res;
  }
};

//https://discuss.leetcode.com/topic/27565/java-python-one-pass-solution-easy-to-understand
//Stefan's other Solution
int countDigitOne(int n) {
    int ones = 0, m = 1, r = 1;
    while (n > 0) {
        ones += (n + 8) / 10 * m + (n % 10 == 1) * r;
        r += n % 10 * m;
        m *= 10;
        n /= 10;
    }
    return ones;
}
