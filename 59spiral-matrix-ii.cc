class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> res(n, vector<int>(n));

    vector<int> nSteps{n, n-1};

    int iDir = 0, ir = 0, ic = -1, num = 1;
    while (nSteps[iDir%2]) {
        for (int i = 0; i < nSteps[iDir%2]; ++i) {
            ir += dirs[iDir][0]; ic += dirs[iDir][1];
            res[ir][ic] = num++;
        }
        nSteps[iDir%2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
  }
};

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int i = 0, j = 0, di = 0, dj = 1;
    for (int k = 1; k <= n*n; k++) {
      res[i][j] = k;
      if (i+di < 0 || j+dj < 0 || res[(i+di)%n][(j+dj)%n]) {
        int tmp = di;
        di = dj;
        dj = -tmp;
      }
      i += di;
      j += dj;
    }
    return res;
  }
};
