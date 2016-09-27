class Solution {
public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    return sum(root, false); // return (root->left ? sum(root->left, true) : 0) + (root->right ? sum(root->right, false) : 0);
  }
private:
  int sum(TreeNode* root, bool isleft) {
    if (!root->left && !root->right)
      if (isleft) return root->val;
      else return 0;
    return (root->left ? sum(root->left, true) : 0) + (root->right ? sum(root->right, false) : 0);
  }
};
