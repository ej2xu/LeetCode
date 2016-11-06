class Solution {
public:
    bool isSubsequence(string s, string t) {
      const char *s = s.c_str(), *t = t.c_str();
      while (*t)
        s += *s == *t++;
      return !*s;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
      if (s.empty()) return true;
      const char *sc = s.c_str(), *tc = t.c_str();
      while (*tc) {
        sc += *sc == *tc++;
        if (!*sc) return true;
      }
      return false;
    }
};
