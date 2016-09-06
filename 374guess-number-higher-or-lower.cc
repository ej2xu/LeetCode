// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
      int l = 1, m, tmp;
      while (l <= n) {
        m = l+(n-l)/2;
        tmp = guess(m);
        if (tmp<0)
          l = m+1;
        else if (tmp>0)
          n = m-1;
        else
          return m;
      }
      return -1;
    }
};
