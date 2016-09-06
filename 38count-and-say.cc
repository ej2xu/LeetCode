class Solution {
public:
    string cs(string s) {
      string res;
      int count = 1;
      char cur = s[0];
      for (int i=1; i<s.size(); i++) {
        if (s[i] != cur) {
          res += '0'+count;
          res += cur;
          cur = s[i];
          count = 1;
        }
        else
          count++;
      }
      res += '0'+count;
      res += cur;
      return res;
    }

    string countAndSay(int n) {
      if (n <= 0)
        return "";
      string res = "1";
      for (int i=0; i<n-1;i++)
        res = cs(res);
      return res;
    }
};

//another Solution
string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
