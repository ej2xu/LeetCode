class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      int counts[256] = {};
      for (auto c: magazine)
        counts[c]++;
      for (auto c: ransomNote)
        counts[c]--;
      for (auto count: counts)
        if (count < 0)
          return false;
      return true;
    }
};
