class Solution {
public:
  string toHex(int num) {
    if (!num) return "0";
    string res;
    bool neg = num < 0;
    if (neg) num = -num-1;
    while (num) {
      int digit = num % 16;
      res += (digit >= 10 ? digit - 10 + 'a' : digit + '0');
      num /= 16;
    }
    if (neg) {
      for (auto &c: res)
        c = c >= 'a' ? 'f' - c + '0' : c <= '5' ? '5' - c + 'a': 15- (c - '0') + '0';
      res.append(8-res.size(), 'f');
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
