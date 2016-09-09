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
 vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> res;
  traverse(root, 0, res);
  reverse(res.start(), res.end());
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

class Solution {
public:
 vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> res;
  traverse(root, 0, res);
  return res;
 }
private:
 void traverse(TreeNode *p, int level, vector<vector<int>> &res) {
   if (p) {
     if (level==res.size())
       res.emplace(res.begin());
     traverse(p->left, level+1, res);
     traverse(p->right, level+1, res);
     res[res.size()-level-1].push_back(p->val);
   }
 }
