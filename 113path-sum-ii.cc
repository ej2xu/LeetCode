class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(root, sum, path, res);
    return res;
  }
private:
  void dfs(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
    if (root) {
      sum -= root->val;
      path.push_back(root->val);
      if (!root->left && !root->right) {
        if (sum == 0)
          res.push_back(path);
      }
      else {
        dfs(root->left, sum, path, res);
        dfs(root->right, sum, path, res);
      }
      path.pop_back();
    }
  }
};
