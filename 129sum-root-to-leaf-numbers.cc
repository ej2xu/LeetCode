class Solution {
public:
  int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
  }
private:
  int dfs(TreeNode *p, int sum) {
    return p ? p->left || p->right ? dfs(p->left, sum*10+p->val)+dfs(p->right, sum*10+p->val) : sum*10+p->val : 0;
  }
};
