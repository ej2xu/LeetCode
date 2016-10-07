class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    if (root->left) {
      TreeNode *x = root;
      while (x->left) {
        x = x->left;
        while (x->right) x = x->right;
      }
      flatten(root->left);
      flatten(root->right);
      x->right = root->right;
      root->right = root->left;
      root->left = NULL;
    } else
      flatten(root->right);
  }
};

class Solution {
public:
  void flatten(TreeNode *root) {
    for (; root; root = root->right)
      if (root->left) {
        TreeNode *x = root->left;
        while (x->right) x = x->right;
        // flatten(root->right);
        x->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
  }
};

class Solution {
public:
  void flatten(TreeNode *root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
private:
  TreeNode *prev = NULL;
};
