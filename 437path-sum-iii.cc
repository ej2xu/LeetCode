class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    unordered_map<int, int> presum({{0, 1}});
    return dfs(root, 0, sum, presum);
  }

private:
  int dfs(TreeNode* root, int sum, int target, unordered_map<int, int> &presum) {
    if (!root) return 0;
    sum += root->val;
    int res = 0;
    auto it = presum.find(sum-target);
    if (it != presum.end())
      res += it->second;
    presum[sum]++;
    res += dfs(root->left, sum, target, presum) + dfs(root->right, sum, target, presum);
    presum[sum]--;
    return res;
  }
};
