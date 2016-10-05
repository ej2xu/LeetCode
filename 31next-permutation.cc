class Solution {
public:
  void nextPermutation(vector<int>& a) {
    int s = a.size(), i = s-1, j = s-1;
    for (; i > 0; i--)
      if (a[i-1] < a[i]) break;
    if (i) {
      for (; j > i-1; j--)
        if (a[j] > a[i-1]) break;
        swap(a[i-1], a[j]);
    }
    reverse(a, i, s-1);
  }
private:
  void reverse(vector<int> &a, int s, int e) {
    while (s<e)
      swap(a[s++], a[e--]);
  }
};
