class Solution {
public:
  int rob(vector<int>& a) {
    int l = a.size();
    if (l == 1) return a[0];
    return max(range(a, 0, l-1), range(a, 1, l));
  }
private:
  int range(vector<int>& a, int l, int h) {
    int pre = 0, cur = 0;
    for (int i = l; i < h; i++) {
      int tmp = max(pre+a[i], cur);
      pre = cur;
      cur = tmp;
    }
    return cur;
  }
};
