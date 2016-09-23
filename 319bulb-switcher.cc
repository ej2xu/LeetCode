class Solution {
public:
  int bulbSwitch(int n) {
    return sqrt(n);
  }
};

//brute force
class Solution {
public:
  int bulbSwitch(int n) {
    char bulbs[n+1] = {0};
    for (int i = 2; i <= n; i++)
      for (int j = i; j <= n; j += i)
        bulbs[j] ^= 1;
    int sum = n;
    for (int i = 1; i <= n; i++)
      sum -= bulbs[i];
    return sum;
  }
};
