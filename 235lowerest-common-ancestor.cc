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
      while (x) {
        if (x->val > p->val && x->val > q->val)
          x = x->left;
        else if (x->val < p->val && x->val < q->val)
          x = x-> right;
        else break;
      }
      return x;
    }
};

// recursive Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || root==p || root==q) return root;
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
