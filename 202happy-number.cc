class Solution {
public:
    int next(int n) {
      int result = 0, tmp;
      while (n) {
        tmp = n%10;
        result += tmp*tmp;
        n /= 10;
      }
      return result;
    }

    bool isHappy(int n) {
      int fast = next(n);
      while (n != fast) {
           n = next(n);
          fast = next(next(fast));
          if (fast == 1) return true;
      }
      return n == 1;
    }
};
