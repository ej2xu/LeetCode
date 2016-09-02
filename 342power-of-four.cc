class Solution {
public:
    bool isPowerOfFour(int n) {
      return n&0x55555555 && !(n&n-1);
    }
};
