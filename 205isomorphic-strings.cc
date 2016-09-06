class Solution {
public:
    bool isIsomorphic(string s, string t) {
      char m[127] = {};
      for (size_t i = 0; i<s.length(); i++) {
        if (!m[s[i]]) {
          if (find(m, m+127, t[i]) == m+127)
            m[s[i]] = t[i];
          else
            return false;
        }
        else if (m[s[i]] != t[i])
          return false;
      }
      return true;
    }
};

//MaskRay's solution using last position of the same char
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;
    size_t ms[127] = {}, mt[127] = {};
    for (size_t i = 0; i < s.size(); i++) {
      if (ms[s[i]] != mt[t[i]])
        return false;
      ms[s[i]] = mt[t[i]] = i+1;
    }
    return true;
  }
};
