class Solution {
public:
  string minAbbreviation(string target, vector<string>& d) {
    int l = target.size();
    d.erase(remove_if(d.begin(), d.end(), [](const string& x) {
        return x.size() > l;
    }), v.end());
    string cur = to_string(l);
    while () {
      for (int i = 0; i < d.size(); i++)
        if (!valid(d[i], cur)) break;
      if (i == d.size()) return cur;
      cur = target[0]+to_string(l-1);
    }
  }
private:
  bool valid(string word, string abbr) {
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
