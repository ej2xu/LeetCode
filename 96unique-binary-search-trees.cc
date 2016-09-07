class Solution {
public:
    int numTrees(int n) {
      int a[n+1] = {};
      a[0] = 1;
      for (int i=1; i<=n; i++)
        for (int k = 0; k < i; k++)
          a[i] = a[k]*a[i-k-1];
      return a[n];
    }
};

//a[n] is indeed Catalan number {2n \choose n}/(n+1)
int numTrees(int n) {
    long long ans=1,i;
    for(i=1;i<=n;i++)
        ans = ans*(i+n)/i;
    return ans/i;
}
