class Solution {
public:
  int lastRemaining(int n) {
    return n == 1 ? 1 : 2*(n/2+1-lastRemaining(n/2));
  }
};

class Solution {
public:
  int lastRemaining(int n) {
    bool left = true;
    int head = 1, step = 1, remain = n;
    while (remain > 1) {
      if (left || remain&1)
        head += step;
      left = !left;
      step <<= 1;
      remain >>= 1;
    }
    return head;
  }
};
