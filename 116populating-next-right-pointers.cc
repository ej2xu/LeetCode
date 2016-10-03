class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    if (root->left)
      root->left->next = root->right;
    if (root->next && root->right)
      root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
  }
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    TreeLinkNode *pre = root, *cur;
    while (pre->left) {
      cur = pre;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) cur->right->next = cur->next->left;
        cur = cur->next;
      }
      pre = pre->left;
    }
  }
};
