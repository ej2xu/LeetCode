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
  int rob(TreeNode* root) {
    return rec(root).second;
  }
private:
  pair<int, int> rec(TreeNode *p) {
    if (!p) return {0, 0};
    pair<int, int> lm = rec(p->left), rm = rec(p->right);
    int res = lm.second+rm.second;
    return {res, max(res, p->val + lm.first + rm.first)};
  }
};
