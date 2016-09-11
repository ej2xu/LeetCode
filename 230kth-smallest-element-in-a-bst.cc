/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//using size k vector as a stack (large enough, save space, faster operation)
class Solution {
public:
    int kthSmallest(TreeNode* p, int k) {
      vector<TreeNode *> s(k);
      int i = 0, j = k;
      while (true) {
        while (p) {
          s[i++%k] = p;
          p = p->left;
        }
        p = s[--i%k];
        if (!--j)
          return p->val;
        p = p->right;
      }
    }
};

//recursive solution, also in-order tranversal
int kthSmallest(TreeNode* root, int& k) {
    if (root) {
        int x = kthSmallest(root->left, k);
        return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
    }
}
