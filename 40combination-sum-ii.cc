class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
      sort(cand.begin(), cand.end());
      vector<vector<int>> res;
      vector<int> comb;
      combSum(cand, target, res, comb, 0);
      return res;
    }

    void combSum(vector<int>& cand, int target, vector<vector<int>>& res, vector<int> &comb, int begin) {
      if (!target) {
        res.push_back(comb);
        return;
      }
      for (int i = begin; i < cand.size() && cand[i] <= target; i++) {
        if (i==begin || cand[i]!=cand[i-1]) {
          comb.push_back(cand[i]);
          combSum(cand, target-cand[i], res, comb, i+1);
          comb.pop_back();
        }
      }
    }
};
