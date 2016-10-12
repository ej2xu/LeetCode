class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &mat) {
    summat = mat;
    for (int i = 0; i < summat.size(); i++)
      for (int j = 0; j < summat[0].size(); j++) {
        if (i) summat[i][j] += summat[i-1][j];
        if (j) summat[i][j] += summat[i][j-1];
        if (i&&j) summat[i][j] -= summat[i-1][j-1];
      }
  }

  int sumRegion(int r1, int c1, int r2, int c2) {
    int res = summat[r2][c2];
    if (r1) res -= summat[r1-1][c2];
    if (c1) res -= summat[r2][c1-1];
    if (r1&&c1) res += summat[r1-1][c1-1];
    return res;
  }
private:
  vector<vector<int>> summat;
};
