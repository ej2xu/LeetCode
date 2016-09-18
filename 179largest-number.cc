class Solution {
public:
    string largestNumber(vector<int>& nums) {
      int len = nums.size();
      vector<string> numstrs(len);
      for (int i = 0; i < len; i++)
        numstrs[i] = to_string(nums[i]);
      sort(numstrs.begin(), numstrs.end(), [](const string &x, const string &y) {
        return x+y > y+x;
      });
      if (numstrs[0] == "0")
        return "0";
      string res;
      for (auto &s: numstrs)
        res += s;
      return res;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      int len = nums.size();
      vector<string> numstrs(len);
      for (int i = 0; i < len; i++)
        numstrs[i] = to_string(nums[i]);
      sort(numstrs.begin(), numstrs.end(), [](const string &x, const string &y) {
        size_t m = x.size(), n = y.size(), i = 0;
        for (; i < m+n; i++) {
          int d = (i < m ? x[i] : y[i-m]) - (i < n ? y[i] : x[i-n]);
          if (d > 0) return true;
          if (d < 0) return false;
        }
        return false;
      });
      if (numstrs[0] == "0")
        return "0";
      string res;
      for (auto &s: numstrs)
        res += s;
      return res;
    }
};
