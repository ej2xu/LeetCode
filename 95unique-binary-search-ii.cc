class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    if (!n) return vector<TreeNode*> ();
    vector<vector<vector<TreeNode*>>> cache(n, vector<vector<TreeNode*>>(n));
    vector<TreeNode*> dummy(1, nullptr);
    return gentreerange(0, n-1, cache, dummy);
  }
private:
  vector<TreeNode*> gentreerange(int start, int end, vector<vector<vector<TreeNode*>>> &cache, vector<TreeNode*> &dummy) {
    if (start > end)
      return dummy;
    if (cache[start][end].size())
      return cache[start][end];
    vector<TreeNode*> res;
    for (int k = start; k <= end; k++) {
      auto l = gentreerange(start, k-1, cache, dummy);
      auto r = gentreerange(k+1, end, cache, dummy);
      for (auto lnode: l)
        for (auto rnode: r) {
          TreeNode *root = new TreeNode(k+1);
          root->left = lnode;
          root->right = rnode;
          res.push_back(root);
        }
    }
    cache[start][end] = res;
    return res;
  }
};

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode *> result[n+1] = {};
    if (!n)
        return result[0];
    result[0].push_back(nullptr);
    for (int len = 1; len <= n; len++)
        for (int j = 0; j < len; j++)
            for (auto nodeL : result[j])
                for (auto nodeR : result[len - j - 1]) {
                    TreeNode *node = new TreeNode(j + 1);
                    node->left = nodeL;
                    node->right = clone(nodeR, j + 1);
                    result[len].push_back(node);
                }
    return result[n];
  }
private:
  TreeNode* clone(TreeNode* n, int offset) {
    if (!n)
        return NULL;
    TreeNode* node = new TreeNode(n->val + offset);
    node->left = clone(n->left, offset);
    node->right = clone(n->right, offset);
    return node;
  }
};

//MaskRay's Solution
class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (!n) return vector<TreeNode*> {};
    vector<vector<vector<TreeNode*>>> a(n, vector<vector<TreeNode*>>(n));
    vector<TreeNode*> dummy(1, nullptr);
    for (int i = n-1; i >= 0; i--)
      for (int j = i; j < n; j++)
        for(int k = i; k <= j; k++)
          for (auto lt: i < k ? a[i][k-1] : dummy)
            for (auto rt: k < j ? a[k+1][j] : dummy) {
              auto x = new TreeNode(k+1);
              x->left = lt;
              x->right = rt;
              a[i][j].push_back(x);
            }
    return a[0][n-1];
  }
};
