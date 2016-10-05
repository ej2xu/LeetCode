class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    res.clear();
    sort(nums.begin(), nums.end());
    genperm(nums, 0);
    return res;
  }
private:
  vector<vector<int>> res;
  void genperm(vector<int> a, int pos) {
    if (pos == a.size()-1)
      res.push_back(a);
    else
      for (int i = pos; i < a.size(); i++)
        if (i == pos || a[pos] != a[i]) {
          swap(a[pos], a[i]);
          genperm(a, pos+1);
        }
  }
};

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    res.clear();
    perm.clear();
    bool used[nums.size()] = {false};
    sort(nums.begin(), nums.end());
    backtrack(nums, used);
    return res;
  }
private:
  vector<vector<int>> res;
  vector<int> perm;
  void backtrack(vector<int>& nums, bool used[]) {
    if (perm.size() == nums.size())
      res.push_back(perm);
    else
      for (int i = 0; i < nums.size(); i++) {
        if (used[i] || i && nums[i] == nums[i-1] && !used[i-1]) continue;
        perm.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, used);
        used[i] = false;
        perm.pop_back();
      }
  }
};

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &a) {
    vector<vector<int> > res;
    sort(a.begin(), a.end());
		res.push_back(a);
    int s = a.size(), i, j;
		while (true) {
			for (i = s-1; i > 0; i--)
				if (a[i-1] < a[i]) break;

      if (!i) break;

			for (j = s-1; j > i-1; j--)
				if (a[j] > a[i-1]) break;
			swap(a[i-1], a[j]);
			reverse(a, i, s-1);
			res.push_back(a);
		}
		return res;
  }
private:
	void reverse(vector<int> &a, int s, int e) {
		while (s<e)
			swap(a[s++], a[e--]);
  }
};
