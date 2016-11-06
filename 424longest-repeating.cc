class Solution {
public:
  int characterReplacement(string s, int k) {
    glomax = 0;
    for (auto ch: s)
      letters.insert(ch);
    rec(s, 0, k, 0);
    return glomax;
  }
private:
  int glomax;
  unordered_set<char> letters;
  void rec(string &s, int i, int k, int curmax) {
    if (i < s.size()) {
      char cur = s[i];
      if (!k) {
        if (!i || s[i] == s[i-1]) {
          glomax = max(glomax, curmax+1);
          rec(s, i+1, k, curmax+1);
        } else {
          rec(s, i+1, k, 1);
        }
      } else {
        k--;
        for (char ch: letters) {
          s[i] = ch;
          if (s[i] == cur) k++;
          if (!i || s[i] == s[i-1]) {
            glomax = max(glomax, curmax+1);
            rec(s, i+1, k, curmax+1);
          } else {
            rec(s, i+1, k, 1);
          }
          if (ch == cur) k--;
        }
        s[i] = cur;
      }
    }
  }
};
