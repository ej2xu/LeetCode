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
    TreeNode* lowestCommonAncestor(TreeNode* x, TreeNode* p, TreeNode* q) {
      if (p->val > q->val)
        swap(p, q);
      while (x) {
        if (x->val > q->val)
          x = x->left;
        else if (x->val < p->val)
          x = x-> right;
        else break;
      }
      return x;
    }
};

// recursive Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return (root->val - p->val) * (root->val - q->val) < 1 ? root :
         lowestCommonAncestor(p->val < root->val ? root->left : root->right, p, q);
    }
};
