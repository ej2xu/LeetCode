class Solution {
public:
    int integerBreak(int n) {
      if (n <= 3) return n-1;
      int a[n+1] = {};
      for (int i = 1; i <= n; i++) {
        a[i] = i;
        for (int j = 1; j <= i-1; j++)
          a[i] = max(a[i], a[j]*a[i-j]);
      }
      return a[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
      if (n <= 3) return n-1;
      if (!(n%3)) return pow(3, n/3);
      if (n%3 == 1) return pow(3, (n-4)/3) * 4;
      return pow(3, (n-2)/3) * 2;
    }
};
