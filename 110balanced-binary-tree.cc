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
    int depth(TreeNode* root) {
      return root ? 1+ max(depth(root->left), depth(root->right)) : 0;
    }
    bool isBalanced(TreeNode* root) {
      if (!root) return true;
      return abs(depth(root->left)-depth(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

// MaskRay's solution: one tranversal
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    bool b = true;
    h(root, b);
    return b;
  }
  int h(TreeNode *p, bool &b) {
    if (! p)
      return 0;
    int hl = h(p->left, b), hr = h(p->right, b);
    if (abs(hl-hr) > 1) b = false;
    return max(hl, hr) + 1;
  }
};

//same idea
class solution {
public:
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};
