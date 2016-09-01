class Solution {
public:
  int f(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
  }
  int romanToInt(string s) {
    int result = 0, size = s.size(), cur, prev;
    if (size != 0) {
      result += f(s[0]);
      prev = result;
    }
    for (int i = 1; i < s.size(); i++) {
      cur = f(s[i]);
      if (prev < cur)
        result += cur-2*prev;
      else
        result += cur;
      prev = cur;
    }
    return result;
  }
};
