class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    while(i < abbr.size() && j < word.size()) {
      int shift = 0;
      if (isdigit(abbr[i])) {
        if (abbr[i] == '0') return false;
        while (i < abbr.size() && isdigit(abbr[i]))
          shift = shift*10 + abbr[i++] - '0';
        j += shift;
      }
      else if (abbr[i++] != word[j++])
        return false;
    }
    return i == abbr.size() && j == word.size();
  }
};
