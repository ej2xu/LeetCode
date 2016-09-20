class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < 1 << nums.size(); i++) {
      sub.clear();
      for (int j = 0; j < nums.size(); j++)
        if (i & 1 << j)
          if (j && nums[j] == nums[j-1] && !(i & 1 << j-1))
            goto L1;
          else
            sub.push_back(nums[j]);
      res.push_back(sub);
    L1:;
    }
    return res;
  }
};

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > res(1);
    sort(S.begin(),S.end());
    int count;
    for(int i=0; i<S.size(); i += count) {
      count = 1;
      while(count + i<S.size() && S[count+i]==S[i])  count++;
      int previousN = res.size();
      for(int k=0; k<previousN; k++){
        vector<int> instance = res[k];
        for(int j=0; j<count; j++){
          instance.push_back(S[i]);
          res.push_back(instance);
        }
      }
    }
    return res;
    }
};

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> res(0);
    sort(S.begin(), S.end());
    int size = 0, startIndex = 0;
    for (int i = 0; i < S.size(); i++) {
        startIndex = i && S[i] == S[i - 1] ? size : 0;
        size = res.size();
        for (int j = startIndex; j < size; j++) {
            vector<int> temp = res[j];
            temp.push_back(S[i]);
            ret.push_back(temp);
        }
    }
    return ret;
}
