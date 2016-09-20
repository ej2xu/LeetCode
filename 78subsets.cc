class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    subgen(res, sub, nums, 0);
    return res;
  }
private:
  void subgen(vector<vector<int>>& res, vector<int> &sub, vector<int>& nums, int begin) {
    if (begin == nums.size())
      res.push_back(sub);
    else {
      sub.push_back(nums[begin]);
      subgen(res, sub, nums, begin+1);
      sub.pop_back();
      subgen(res, sub, nums, begin+1);
    }
  }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        genSubsets(nums, 0, sub, subs);
        return subs;
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    for (int i = 0; i < 1 << nums.size(); i++) {
      sub.clear();
      for (int j = 0; j < nums.size(); j++)
        if (i & 1 << j)
          sub.push_back(nums[j]);
      res.push_back(sub);
    }
    return res;
  }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};
