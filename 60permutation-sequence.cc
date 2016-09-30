class Solution {
public:
  string getPermutation(int n, int k) {
    int f = 1, i;
    string res(n, '0');
    for (i = 1; i <= n; i++) {
      f *= i;
      res[i-1] += i;
    }
    for (i = 0, k--; i < n; i++) {
      f /= n-i;
      int j = i+k/f;
      char c = res[j];
      for (; i<j; j--)
        res[j] = res[j-1];
      res[i] = c;
      k %= f;
    }
    return res;
  }
};

//MaskRay's Solution
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string getPermutation(int n, int k) {
    int f[] = {1,1,2,6,24,120,720,5040,40320};
    vector<bool> a(n, true);
    string r;
    k--;
    ROF(i, 0, n) {
      int t = k/f[i], j = 0;
      k %= f[i];
      while (! a[j]) j++;
      while (t--)
        while (! a[++j]);
      a[j] = false;
      r += '1'+j;
    }
    return r;
  }
};

// bit twiddling

#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string getPermutation(int n, int k) {
    int f[] = {1,1,2,6,24,120,720,5040,40320};
    int a = ~0;
    string r;
    k--;
    ROF(i, 0, n) {
      int t = k/f[i];
      k %= f[i];
      int b = a;
      while (t--)
        b &= b-1;
      int j = __builtin_ctz(b);
      a ^= 1<<j;
      r += '1'+j;
    }
    return r;
  }
};

// 陈霜

#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string getPermutation(int n, int k) {
    int f[] = {1,1,2,6,24,120,720,5040,40320};
    long long a = 0x987654321;
    string r;
    k--;
    ROF(i, 0, n) {
      int t = k/f[i];
      k %= f[i];
      r += '0'|a>>4*t&15;
      a = a&(1LL<<4*t)-1|a>>4*(t+1)<<4*t;
    }
    return r;
  }
};
