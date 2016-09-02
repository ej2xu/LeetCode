class Solution {
public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      while (n) {
        count += n & 1;
        n >>= 1;
      }
      return count;
    }
};

// Brian Kernighan's solution in Book "The C programming language"
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int sum = 0;
      while (n) {
        sum++;
        n &= (n-1);
      }
      return sum;
    }
};
