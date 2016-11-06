class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (!digits.size())
      return res;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
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

//BFS Solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (!digits.size())
            return res;
        string charmap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempres;
            string chars = charmap[digits[i] - '2'];
            for (int c = 0; c < chars.size(); c++)
                for (int j = 0; j < res.size(); j++)
                    tempres.push_back(res[j]+chars[c]);
            res = tempres;
        }
        return res;
    }
};
