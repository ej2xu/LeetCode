class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int m = mat.size();
    if (!m) return res;
    int n  = mat[0].size();
    for (int i = 0; i < (min(m, n)+1)/2; i++) {
      for (int j = i; j < n-i; j++)
        res.push_back(mat[i][j]);
      for (int j = i+1; j < m-i; j++)
        res.push_back(mat[j][n-i-1]);
      if (i != m/2)
        for (int j = n-i-2; j >= i; j--)
          res.push_back(mat[m-i-1][j]);
      if (i != n/2)
        for (int j = m-i-2; j > i; j--)
          res.push_back(mat[j][i]);
    }
    return res;
  }
};

//stellari's solution using direction array
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    int nr = matrix.size();     if (nr == 0) return res;
    int nc = matrix[0].size();
    
    vector<int> nSteps{nc, nr-1};

    int iDir = 0;   // index of direction.
    int ir = 0, ic = -1;    // initial position
    while (nSteps[iDir%2]) {
        for (int i = 0; i < nSteps[iDir%2]; ++i) {
            ir += dirs[iDir][0]; ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir%2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
}
