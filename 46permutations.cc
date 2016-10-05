class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    res.clear();
    genperm(nums, 0);
    return res;
  }
private:
  vector<vector<int>> res;
  void genperm(vector<int>& a, int pos) {
    if (pos == a.size()-1)
      res.push_back(a);
    else
      for (int i = pos; i < a.size(); i++) {
        swap(a[pos], a[i]);
        genperm(a, pos+1);
        swap(a[pos], a[i]);
      }
  }
};
