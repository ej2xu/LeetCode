class Solution {
public:
    int countDigitOne(int n) {
      return n%10*countDigitOne(n/10);
    }
};
