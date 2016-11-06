class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& dict) {
    int n = s.size();
    bool *dp = new bool[n+1]();
    dp[n] = true;
    for (int i = n-1; i >= 0; i--)
      for (int j = i+1; j <= n; j++)
        if (dp[j] && dict.count(s.substr(i, j-i))) {
          dp[i] = true;
          break;
        }
    return dp[0];
  }
};

// MaskRay's Solution
class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> f(s.size()+1);
    f[s.size()] = true;
    for (int i = s.size(); --i >= 0; )
      for (auto &w: dict)
        if (i+w.size() <= s.size() && f[i+w.size()] && ! strncmp(&s[i], w.c_str(), w.size())) {
          f[i] = true;
          break;
        }
    return f[0];
  }
};

// BFS
bool wordBreak(string s, unordered_set<string> &dict) {
  queue<int> BFS;
  unordered_set<int> visited;

  BFS.push(0);
  while(BFS.size()) {
    int start = BFS.front();
    BFS.pop();
    if(visited.find(start) == visited.end()) {
      visited.insert(start);
      for(int j=start; j<s.size(); j++) {
        string word(s, start, j-start+1);
        if(dict.count(word)) {
          BFS.push(j+1);
          if(j+1 == s.size())
            return true;
        }
      }
    }
  }
  return false;
}
