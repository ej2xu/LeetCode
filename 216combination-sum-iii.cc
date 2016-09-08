class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> res;
      vector<int> comb;
      combSum(n, res, comb, 1, k);
      return res;
    }

    void combSum(int target, vector<vector<int>>& res, vector<int> &comb, int begin, int count) {
      if (!target && !count) {
        res.push_back(comb);
        return;
      }
      if (count--) {
        for (int i = begin; i<=target && i<=9; i++) {
          comb.push_back(i);
          combSum(target-i, res, comb, i+1, count);
          comb.pop_back();
        }
      }
    }
};
