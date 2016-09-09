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
    vector<int> preorderTraversal(TreeNode* p) {
      vector<int> res;
      stack<TreeNode *> s;
      while (true) {
        while (p) {
          if (p->right)
            s.push(p->right);
          res.push_back(p->val);
          p = p->left;
        }
        if (s.empty()) break;
        p = s.top();
        s.pop();
      }
      return res;
    }
};
