class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    int a[n+1] = {0};
    a[0] = 1;
    for (int i=1; i<=n; i++)
      for (int k = 0; k < i; k++)
        a[i] += a[k]*a[i-k-1];
    return a[n];
  }
};
