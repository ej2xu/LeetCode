class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length())
        return false;
      int counts[26] = {};
      for (auto c: s)
        counts[c-'a']++;
      for (auto c: t)
        if (--counts[c-'a'] < 0)
          return false;
      return true;
    }
};
