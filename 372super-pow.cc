// 1337 = 7*191. phi(1337) = 6 * 190 = 1140
class Solution {
public:
  int superPow(int a, vector<int>& b) {
    a %= 1337;
    if (!a) return 0;
    int count = 0;
    for (int d: b)
      count = (count*10+d)%1140;
    if (!count)
      count += 1440; //miss this at first place. https://discuss.leetcode.com/topic/50586/math-solusion-based-on-euler-s-theorem-power-called-only-once-c-java-1-line-python/20
    return powmod(a, count, 1337);
  }
  int powmod(int a, int b, int m) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % m)
      if (b & 1)
        res = res * a % m;
    return res;
  }
};

//recursive
class Solution {
public:
    int superPow(int a, vector<int>& b) {
      if (b.empty()) return 1;
      int last_digit = b.back();
      b.pop_back();
      return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
private:
  const int base = 1337;
  int powmod(int a, int k) {
    a %= base;
    int res = 1;
    while (k--)
        res = (res * a) % base;
    return res;
  }
};
