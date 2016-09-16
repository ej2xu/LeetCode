//againest1's solution
class Solution {
public:
  int singleNumber(vector<int> &a) {
    int one = 0, two = 0;
    for (int x: a) {
      one = (one ^ x) & ~ two;
      two = (two ^ x) & ~ one;
    }
    return one;
  }
};

class Solution {
public:
  int singleNumber(vector<int> &a) {
    int one = 0, two = 0;
    for (int x: a) {
      two = one & (two ^ x);
      one = two | (one ^ x);
    }
    return one;
  }
};
