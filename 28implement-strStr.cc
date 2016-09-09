class Solution {
public:
    int strStr(string haystack, string needle) {
      int hl = haystack.size(), nl = needle.size();
      for (int i=0; i<=hl-nl; i++)
        for (int j=0; ; j++) {
          if (j == nl) return i;
          if (haystack[i+j] != needle[j]) break;
        }
      return -1;
    }
};
