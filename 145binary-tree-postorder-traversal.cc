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
    vector<int> postorderTraversal(TreeNode* p) {
      vector<int> res;
      stack<TreeNode *> s;
      while (true) {
        while (p) {
          s.push(p);
          p = p->left;
        }
        while (!s.empty() && s.top()->right == p) {
          p = s.top();
          s.pop();
          res.push_back(p->val);
        }
        if (s.empty()) break;
        p = s.top()->right;
      }
      return res;
    }
};

// Morris post-order traversal
class Solution {
  void reverse_right_chain(TreeNode *x, TreeNode *y) {
    TreeNode *p = x, *q = x->right, *right;
    while (p != y) {
      right = q->right;
      q->right = p;
      p = q;
      q = right;
    }
  }
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode aux(0), *p = &aux;
    aux.left = root;
    aux.right = NULL;
    while (p) {
      TreeNode *q = p->left;
      if (q) {
        while (q->right && q->right != p) q = q->right;
        if (q->right == p) {
          reverse_right_chain(p->left, q);
          for (TreeNode *r = q; ; r = r->right) {
            ret.push_back(r->val);
            if (r == p->left) break;
          }
          reverse_right_chain(q, p->left);
          q->right = NULL;
        } else {
          q->right = p;
          p = p->left;
          continue;
        }
      }
      p = p->right;
    }
    return ret;
  }
};
