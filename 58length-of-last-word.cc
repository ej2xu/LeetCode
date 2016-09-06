class Solution {
public:
    int lengthOfLastWord(string s) {
      int i = s.size();
      int l = 0;
      while (i && s[--i]==' ');
      while (i>=0 && isalpha(s[i--]))
        l++;
      return l;
     }
};
