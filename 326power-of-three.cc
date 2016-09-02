class Solution {
public:
    bool isPowerOfThree(int n) {
      if (!n) return false;
      if (n == 1) return true;
      return n == n/3 * 3 && isPowerOfThree(n/3);
    }
};

// Solution using the largest Int power of three
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && int(pow(3, int(log(INT_MAX) / log(3)))) % n == 0;
  }
};
