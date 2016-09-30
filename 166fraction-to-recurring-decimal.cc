class Solution {
public:
  string fractionToDecimal(int64_t n, int64_t d) {
    if (!n) return "0";
    string res;
    if (n < 0 ^ d < 0)
      res += '-';
    n = abs(n), d = abs(d);
    res += to_string(n/d);
    n %= d;
    if (!n) return res;
    res += '.';
    unordered_map<int, int> map;
    int pos = res.size();
    while (n) {
      if (map.count(n)) {
        res.insert(res.begin()+map[n], '(');
        res += ')';
        break;
      }
      map[n] = pos++;
      n *= 10;
      res += '0' + n/d;
      n %= d;
    }
    return res;
  }
};
