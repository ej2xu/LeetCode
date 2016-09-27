class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    return decode(s, i);
  }
private:
  string decode(string s, int &i) {
    string res;
    while (i < s.size() && s[i] != ']') {
      if (!isdigit(s[i]))
        res += s[i++];
      else {
        int rep = s[i++] - '0';
        while (isdigit(s[i]))
          rep = rep * 10 + s[i++] - '0';
        i++;
        string repstr = decode(s, i);
        i++;
        while (rep--)
          res += repstr;
      }
    }
    return res;
  }
};
