class Solution {
public:
    int hIndex(vector<int>& c) {
      int l = c.size(), k = 1;
      sort(c.begin(), c.end());
      for (int i = l-1; k <= l; i--, k++)
        if (c[i] < k) break;
      return --k;
    }
};

//O(n) solution
class Solution {
public:
  int hIndex(vector<int> &a) {
    int n = (int)a.size(), s = n, ans = 0;
    vector<int> c(n);
    for (int x: a)
      if (x < n)
        c[x]++;
    for (int i = 0; i < n; i++)
      if ((s -= c[i]) > i)
        ans = i+1;
      else break;
    return ans;
  }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), h = 0;
        int* counts = new int[n + 1]();
        for (int c : citations)
            counts[min(c, n)]++;
        for (int i = n; i; i--) {
            h += counts[i];
            if (h >= i) return i;
        }
        return h;
    }
};
