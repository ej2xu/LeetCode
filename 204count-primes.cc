class Solution {
public:
  int countPrimes(int n) {
    if (n < 3) return 0;
    int count = 1, m = sqrt(n-1);
    bool isp[n] = {};
    for (int i = 3; i < n; i += 2)
      isp[i] = true;
    for (int i = 3; i < m; i += 2)
      if (isp[i])
        for (int j = i*i, step = i<<1; j < n; j += step)
          isp[j] = false;
    for (int i = 3; i < n; i += 2)
      if (isp[i]) count++;
    return count;
  }
};

//brute force: TLE
class Solution {
public:
  int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++)
      if (isp(i)) count++;
    return count;
  }
private:
  bool isp(int n) {
    for (int i = 2; i*i <= n; i++)
      if (n%i == 0) return false;
    return true;
  }
};
