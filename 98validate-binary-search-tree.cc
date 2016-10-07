class Solution {
public:
  bool isValidBST(TreeNode* root) {
    TreeNode* pre = NULL;
    return isvalid(root, pre);
  }
private:
  bool isvalid(TreeNode *cur, TreeNode *&pre) {
    if (!cur) return true;
    if (!isvalid(cur->left, pre)) return false;
    if (pre && pre->val >= cur->val) return false;
    pre = cur;
    return isvalid(cur->right, pre);
  }
};

//iterative
class Solution {
public:
  bool isValidBST(TreeNode* p) {
    TreeNode *pre = NULL;
    stack<TreeNode *> s;
    for (;;) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      if (s.empty()) return true;
      p = s.top();
      s.pop();
      if (pre && pre->val >= p->val) return false;
      pre = p;
      p = p->right;
    }
  }
};
