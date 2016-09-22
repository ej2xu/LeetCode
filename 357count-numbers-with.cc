class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    int res = 1, count = 9;
    n = min(n, 10);
    for (int i = 0; i < n; i++) {
      res += count;
      count *= 9-i;
    }
    return res;
  }
};
