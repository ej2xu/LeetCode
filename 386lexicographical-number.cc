class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    int next = 1;
    for (int i = 0; i < n; i++) {
      res.push_back(next);
      if (next*10 <= n)
        next *= 10;
      else {
        if (next == n)
          next /= 10;
        while (next % 10 == 9)
          next /= 10;
        next++;
      }
    }
    return res;
  }
};

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    for (int i = 1; i <= 9; i++)
      dfs(i, n, res);
    return res;
  }
private:
  void dfs(int cur, int n, vector<int> &res) {
    if (cur <= n) {
      res.push_back(cur);
      cur *= 10;
      for (int i = 0; i <= 9; i++)
        if (cur+i <= n)
          dfs(cur+i, n, res);
    }
  }
};
