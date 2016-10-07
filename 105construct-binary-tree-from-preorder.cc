class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int &x: inorder)
      inorderm[x] = &x;
    return gentree(&preorder[0], &*preorder.end(), &inorder[0], &*inorder.end());
  }
private:
  unordered_map<int, int*> inorderm;
  TreeNode* gentree(int *pl, int *ph, int *il, int *ih) {
    if (pl == ph) return nullptr;
    TreeNode* root = new TreeNode(*pl);
    int *mid = inorderm[root->val];
    root->left = gentree(pl+1, pl+1+(mid-il), il, mid);
    root->right = gentree(pl+1+(mid-il), ph, mid+1, ih);
    return root;
  }
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    ipos = 0, ppos = 0;
    return gentree(inorder, preorder, NULL);
  }
private:
  int ppos, ipos;
  TreeNode* gentree(vector<int>& inorder, vector<int>& preorder, TreeNode *end) {
    if (ppos == preorder.size()) return NULL;
    TreeNode *root = new TreeNode(preorder[ppos++]);
    if (inorder[ipos] != root->val)
      root->left = gentree(inorder, preorder, root);
    ipos++;
    if (!end || inorder[ipos] != end->val)
      root->right = gentree(inorder, preorder, end);
    return root;
  }
};

// iterative
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return nullptr;
    auto i = preorder.begin(), j = inorder.begin();
    auto root = new TreeNode(*i++);
    stack<TreeNode *> s;
    s.push(root);
    while (i != preorder.end()) {
      auto x = s.top();
      if (x->val != *j) {
        x->left = new TreeNode(*i++);
        x = x->left;
        s.push(x);
      } else {
        s.pop();
        ++j;
        if (s.empty() || s.top()->val != *j) {
          x->right = new TreeNode(*i++);
          x = x->right;
          s.push(x);
        }
      }
    }
    return root;
  }
};
