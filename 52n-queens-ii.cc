class Solution {
public:
  int totalNQueens(int n) {
    count = 0;
    this->n = n;
    bool col[n] = {false}, dia1[2*n-1] = {false}, dia2[2*n-1] = {false};
    genconfig(0, col, dia1, dia2);
    return count;
  }
private:
  int n, count;
  void genconfig(int row, bool c[], bool d1[], bool d2[]) {
    if (row == n)
      count++;
    else
      for (int col = 0; col < n; col++)
        if (!c[col] && !d1[row+col] && !d2[n-1+col-row]) {
          c[col] = d1[row+col] = d2[n-1+col-row] = true;
          genconfig(row+1, c, d1, d2);
          c[col] = d1[row+col] = d2[n-1+col-row] = false;
        }
  }
};

class Solution {
private:
  int c, n;
public:
  int totalNQueens(int n) {
    c = 0;
    this->n = n;
    f(n, 0, 0, 0);
    return c;
  }
  void f(int i, int l, int m, int r) {
    if (! i)
    c++;
    else
    for (int x = (1<<n)-1&~(l|m|r); x; x &= x-1) {
      int y = x & -x;
      f(i-1, (l|y)<<1, m|y, (r|y)>>1);
    }
  }
};
