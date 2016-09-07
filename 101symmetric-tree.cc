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
    bool symm(TreeNode *n1, TreeNode *n2) {
      if (!n1&&!n2) return true;
      if (!n1||!n2) return false;
      return n1->val == n2->val && symm(n1->left, n2->right) && symm(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
      return symm(root, root);
    }
};

//solution using queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> check;

        check.push(root->left);
        check.push(root->right);

        while (!check.empty()) {
            TreeNode* node1 = check.front();
            check.pop();
            TreeNode* node2 = check.front();
            check.pop();
            if ((!node2 && node1) || (!node1 && node2))
              return false;
            if (node1 && node2) {
              if (node1->val != node2->val)
                return false;
              check.push(node1->left);
              check.push(node2->right);
              check.push(node1->right);
              check.push(node2->left);
          }
        }
        return true;
    }
};
