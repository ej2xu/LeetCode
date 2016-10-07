class Solution {
public:
  void nextPermutation(vector<int>& a) {
    int s = a.size(), i = s-1;
    for (; i > 0; i--)
      if (a[i-1] < a[i]) break;
    if (i) {
      int j = s-1;
      for (; a[j] <= a[i-1]; j--);
      swap(a[i-1], a[j]);
    }
    reverse(a.begin()+i, a.end());
  }
};
