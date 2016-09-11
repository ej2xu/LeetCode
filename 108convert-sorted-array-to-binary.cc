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
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return dfs(a, 0, a.size()-1);
    }
private:
    TreeNode* dfs(vector<int> &a, int l, int h) {
      if (l>h) return NULL;
      int m = l+(h-l)/2;
      TreeNode* root = new TreeNode(a[m]);
      root->left = dfs(a, l, m-1);
      root->right = dfs(a, m+1, h);
      return root;
    }
};
