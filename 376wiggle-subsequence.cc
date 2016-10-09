class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int res = 1, n = nums.size(), asc = 0;
    if (n < 2) return n;
    for (int i = 0; i < n-1; i++) {
      if (nums[i] < nums[i+1] && asc <= 0)
        res++, asc = 1;
      if (nums[i] > nums[i+1] && asc >= 0)
        res++, asc = -1;
    }
    return res;
  }
};

int wiggleMaxLength(vector<int>& a) {
  int n = a.size();
  if (n < 2) return n;
  vector<int> asc(n, 0), dsc(n, 0);
  asc[0] = dsc[0] = 1;
  for (int i = 1; i < a.size(); i++) {
    for (int j = 0; j < i; j++)
      if (a[i] > a[j])
        asc[i] = max(asc[i], dsc[j]);
      else if (a[i] < a[j])
        dsc[i] = max(dsc[i], asc[j]);
    asc[i]++;
    dsc[i]++;
  }
  return max(asc[n-1], dsc[n-1]);
}

int wiggleMaxLength(vector<int>& a) {
  int n = a.size();
  if (n < 2) return n;
  int asc = 1, dsc = 1;
  for (int i = 1; i < a.size(); i++)
  if (a[i] > a[i-1])
    asc = dsc+1;
  else if (a[i] < a[i-1])
    dsc = asc+1;
  return max(asc, dsc);
}
