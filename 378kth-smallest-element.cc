class cmp {
  public:
    bool operator() (const tuple<int, int, int> &lhs, const tuple<int, int, int> &rhs) const {
      return get<0>(lhs) > get<0>(rhs);
    }
};

class Solution {
public:
  int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> mHeap;
    for (int i = 0; i < n; i++)
      mHeap.push(make_tuple(mat[0][i], 0, i));
    tuple<int, int, int> res;
    for (int i = 1; i < k; i++) {
      res = mHeap.top();
      mHeap.pop();
      int row = get<1>(res)+1;
      if (row == n) continue;
      int col = get<2>(res);
      mHeap.push(make_tuple(mat[row][col], row, col));
    }
    return get<0>(mHeap.top());
  }
};

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix[0][0], h = matrix.back().back();
    while (l < h) {
      int x = l+(h-l)/2, c = 0, j = matrix[0].size();
      for (auto& a: matrix) {
        while (j && x < a[j-1])
          j--;
        if (!j) break;
        c += j;
      }
      if (c < k)
        l = x+1;
      else
        h = x;
    }
    return l;
  }
};
