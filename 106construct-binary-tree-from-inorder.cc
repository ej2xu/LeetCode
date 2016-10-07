class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return gentree(&postorder[0], &*postorder.end(), &inorder[0], &*inorder.end());
  }
private:
  TreeNode* gentree(int *pl, int *ph, int *il, int *ih) {
    if (pl == ph) return nullptr;
    TreeNode* root = new TreeNode(ph[-1]);
    int *mid = find(il, ih, root->val);
    root->left = gentree(pl, pl+(mid-il), il, mid);
    root->right = gentree(pl+(mid-il), ph-1, mid+1, ih);
    return root;
  }
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    ipos = inorder.size()-1, ppos = postorder.size()-1;
    return gentree(inorder, postorder, NULL);
  }
private:
  int ppos, ipos;
  TreeNode* gentree(vector<int>& inorder, vector<int>& postorder, TreeNode *end) {
    if (ppos < 0) return NULL;
    TreeNode *root = new TreeNode(postorder[ppos--]);
    if (inorder[ipos] != root->val)
      root->right = gentree(inorder, postorder, root);
    ipos--;
    if (!end || inorder[ipos] != end->val)
      root->left = gentree(inorder, postorder, end);
    return root;
  }
};

// MaskRay's iterative
class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty()) return nullptr;
    stack<TreeNode *> s;
    TreeNode *x = nullptr;
    auto i = inorder.begin(), j = postorder.begin();
    while (j != postorder.end())
      if (! s.empty() && s.top()->val == *j) {
        s.top()->right = x;
        x = s.top();
        s.pop();
        ++j;
      } else {
        auto y = new TreeNode(*i++);
        y->left = x;
        x = nullptr;
        s.push(y);
      }
    return x;
  }
};
