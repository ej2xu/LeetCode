class Solution {
public:
  int findMin(vector<int>& a) {
    int l = 0, h = a.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] > a[h])
        l = m+1;
      else
        h = m;
    }
    return a[l];
  }
};
