class Solution {
public:
    vector<int> getRow(int r) {
      vector<int> res(r+1, 1);
      for (int i = 1; i < r+1; i++)
        for (int j = i-1; j >= 1; j--)
          res[j] += res[j-1];
      return res;
    }
};
