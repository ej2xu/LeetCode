class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    traverse(root, 0, res);
    for (int i = 1; i < res.size(); i+= 2)
      reverse(res[i].begin(), res[i].end());
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<TreeNode *> frontier{root};
    bool rev = false;
    int s;
    while (s = frontier.size()) {
      res.emplace_back();
      vector<TreeNode *> next;
      for (int i = 0; i < s; i++) {
        if (rev)
          res.back().push_back(frontier[s-1-i]->val);
        else
          res.back().push_back(frontier[i]->val);
        if (frontier[i]->left) next.push_back(frontier[i]->left);
        if (frontier[i]->right) next.push_back(frontier[i]->right);
      }
      rev = !rev;
      frontier = next;
    }
    return res;
  }
};

//using queue
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   queue<TreeNode*> q;
   if(root)  q.push(root);
   bool reverse = false;
   vector<vector<int>> zigzagResult;
   while(!q.empty()){
       int size = q.size();
       zigzagResult.push_back(vector<int>(size));
       for(int i=0; i<size; i++){
           int index = (reverse) ? size-i-1 : i;
           zigzagResult.back()[index] = q.front()->val;
           if(q.front()->left)  q.push(q.front()->left);
           if(q.front()->right)  q.push(q.front()->right);
           q.pop();
       }
       reverse = !reverse;
   }
   return zigzagResult;
}
