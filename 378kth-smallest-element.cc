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
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri) {
			mid = le + (ri-le)/2;
			int num = 0;
			for (int i = 0; i < n; i++) {
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
				le = mid + 1;
			else
				ri = mid;
		}
		return le;
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
