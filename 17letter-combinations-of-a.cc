class Solution {
public:
  vector<string> letterCombinations(string digits) {
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> res;
    string comb(digits.size(), ' ');
    f(0, digits, comb, res);
    return res;
  }
private:
  map<char, string> m;
  void f(int k, string &digits, string &comb, vector<string> &res) {
    if (k == digits.size())
      res.push_back(comb);
    else
      for (auto ch: m[digits[k]]) {
        comb[k] = ch;
        f(k+1, digits, comb, res);
      }
  }
};
