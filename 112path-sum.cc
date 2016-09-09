/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    return root ? dfs(root, sum) : false;
  }
private:
  bool dfs(TreeNode *p, int sum) {
    if (!p->left && !p->right)
      if (sum == p->val)
        return true;
      else
        return false;
    else {
      if (p->left && dfs(p->left, sum - p->val))
        return true;
      else
        return p->right && dfs(p->right, sum - p->val);
    }
  }
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    sum -= root->val;
    if (!root->left && !root->right) return sum == 0;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

//MaskRay's one line Solution
class Solution {
public:
    bool hasPathSum(TreeNode *x, int s) {
        return x ? s -= x->val, x->left || x->right ? hasPathSum(x->left, s) + hasPathSum(x->right, s) : !s : false;
    }
};s
