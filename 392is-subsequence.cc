class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i = 0, j=0;
      for (; i<s.size() && j < t.size(); j++)
        if (s[i] == t[j])
          i++;
      return i == s.size();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
      const char *s = s.c_str(), *t = t.c_str();
      while (*t)
        s += *s == *t++;
      return !*s;
    }
};
