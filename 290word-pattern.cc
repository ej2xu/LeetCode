class Solution {
public:
    bool wordPattern(string pattern, string str) {
      map<char, int> p2i;
      map<string, int> w2i;
      istringstream in(str);
      int i = 0, n = pattern.size();
      for(string word; in>>word; i++) {
        if (i == n || w2i[word] != p2i[pattern[i]])
          return false;
        w2i[word] = p2i[pattern[i]] = i+1;
      }
      return i == n;
    }
};
