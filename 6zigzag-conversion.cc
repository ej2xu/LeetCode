class Solution {
public:
    string convert(string s, int r) {
      int l = s.size();
      if (r <= 1 || l <= r)
        return s;
      string res;
      for (int i=0; i<r; i++)
        for (int j = i, k; j<l; j+=2*r-2) {
          res += s[j];
          if (i && i<r-1 && (k=j+2*(r-i)-2) < l)
            res += s[k];
        }
      return res;
    }
};
