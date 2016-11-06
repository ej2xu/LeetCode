class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& dict) {
    vector<string> res;
    if (mem.count(s)) return mem[s];
    int n = s.size();
    bool found = false;
    for (int j = n-1; j >= 0; j--)
      if (dict.count(s.substr(j))) {
        found = true;
        break;
      }
    if (!found) return mem[s] = res;
    for (int i = 1; i < n; i++)
      if (dict.count(s.substr(0, i)))
        for (auto &str: wordBreak(s.substr(i), dict))
          res.push_back(s.substr(0, i) + " " + str);
    if (dict.count(s))
      res.push_back(s);
    return mem[s] = res;
  }
private:
  unordered_map<string, vector<string>> mem;
};

// iterative dp TLE
class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& dict) {
    int n = s.size();
    vector<vector<string>> dp(n);
    for (int i = n-1; i >= 0; i--) {
      if (dict.count(s.substr(i)))
        dp[i].push_back(s.substr(i));
      for (int j = i+1; j < n; j++)
        if (!dp[j].empty() && dict.count(s.substr(i, j-i)))
          for (auto &str: dp[j])
            dp[i].push_back(s.substr(i, j-i) + " " + str);
    }
    return dp[0];
  }
};

// recursive backtrack
class Solution {
private:
  vector<vector<bool>> f;
  vector<bool> g;
  vector<int> r;
  vector<string> rr;
  void h(int i, int n, const string &s) {
    if (i == n) {
      string ss = s;
      for (i = 0; i < r.size(); i++)
        ss.insert(r[i]+i, " ");
      rr.push_back(ss);
    } else
      for (int j = i; j < n; j++)
        if (f[i][j] && g[j+1]) {
          r.push_back(j+1);
          h(j+1, n, s);
          r.pop_back();
        }
  }
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int n = s.size();
    f.assign(n, vector<bool>(n, false));
    g.assign(n+1, false);
    g[n] = true;
    for (int i = n-1; i >= 0; i--)
      for (int j = i; j < n; j++)
        if (dict.count(s.substr(i, j-i+1))) {
          f[i][j] = true;
          if (g[j+1])
            g[i] = true;
        }
    h(0, n, s);
    return rr;
  }
};
