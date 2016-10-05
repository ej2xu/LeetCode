class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    res.clear();
    this->n = n;
    config.assign(n, string(n, '.'));
    genconfig(0);
    return res;
  }
private:
  int n;
  vector<string> config;
  vector<vector<string>> res;
  void genconfig(int row) {
    if (row == n)
      res.push_back(config);
    else
      for (int col = 0; col < n; col++)
        if (isvalid(row, col)) {
          config[row][col] = 'Q';
          genconfig(row+1);
          config[row][col] = '.';
        }
  }
  bool isvalid(int row, int col) {
    for (int i = 0; i < row; i++)
      if (config[i][col] == 'Q')
        return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
      if (config[i][j] == 'Q')
        return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
      if (config[i][j] == 'Q')
        return false;
    return true;
  }
};

//MaskRay's Solution
class Solution {
private:
  int n;
  vector<string> s;
  vector<vector<string>> q;
public:
  vector<vector<string> > solveNQueens(int n) {
    q.clear();
    this->n = n;
    s.assign(n, string(n, '.'));
    f(n, 0, 0, 0);
    return q;
  }
  void f(int i, int l, int m, int r) {
    if (!i)
      q.push_back(s);
    else
      for (int x = (1<<n)-1&~(l|m|r); x; x &= x-1) {
        int y = x & -x;
        s[i-1][__builtin_ctz(y)] = 'Q';
        f(i-1, (l|y)<<1, m|y, (r|y)>>1);
        s[i-1][__builtin_ctz(y)] = '.';
      }
  }
};
