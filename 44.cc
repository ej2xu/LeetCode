class Solution {
public:
  int wordsTyping(vector<string>& s, int r, int c) {
    int res = 0, cur = 0, i = 0;
    for (; i < r; i++) {
      int l = 0;
      while (l + s[cur].size() <= c) {
        printf("cur=%d, l = %d\n", cur, l);
        l += s[cur].size();
        cur++;
        if (cur == s.size()) {
          cur = 0;
          res++;
          if (l+1+s[0].size() > c) {
            i++;
            res *= r / i;
            r = r % i;
            i = 0;
          }
        }
        l++;
      }
    }
    return res;
  }
};
