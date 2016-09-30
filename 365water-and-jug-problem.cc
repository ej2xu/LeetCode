class Solution {
public:
  bool canMeasureWater(int x, int y, int z) {
    return !z || x >= z-y && z % __gcd(x,y) == 0;
  }
};
