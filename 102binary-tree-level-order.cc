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
  vector<vector<int>> levelOrder(TreeNode* root) {
   vector<vector<int>> res;
   traverse(root, 0, res);
   return res;
  }
private:
  void traverse(TreeNode *p, int level, vector<vector<int>> &res) {
    if (p) {
      if (level==res.size())
        res.emplace_back();
      res[level].push_back(p->val);
      traverse(p->left, level+1, res);
      traverse(p->right, level+1, res);
    }
  }
};

//MaskRay's solution using queue
class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> r;
    if (! root) return r;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    while (! q.empty()) {
      TreeNode *x = q.front().first;
      int d = q.front().second;
      q.pop();
      if (r.size() <= d) r.emplace_back();
      r.back().push_back(x->val);
      if (x->left) q.push(make_pair(x->left, d+1));
      if (x->right) q.push(make_pair(x->right, d+1));
    }
    return r;
  }
};
