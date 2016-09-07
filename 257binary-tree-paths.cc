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
    vector<string> paths;
    void genPaths(TreeNode* x, string s) {
      if (x) {
        s += (s.empty()? to_string(x->val) : "->" + to_string(x->val));
        if (!x->left && !x->right)
          paths.push_back(s);
        else {
        genPaths(x->left, s);
        genPaths(x->right, s);
        }
      }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
      genPaths(root, "");
      return paths;
    }
};
