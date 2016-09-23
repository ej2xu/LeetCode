class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> a{1};
    int i = 0, j = 0, k = 0;
    while (--n) {
      int next = min(min(a[i]*2, a[j]*3), a[k]*5);
      a.push_back(next);
      if (next == a[i]*2) i++;
      if (next == a[j]*3) j++;
      if (next == a[k]*5) k++;
    }
    return a.back();
  }
};
